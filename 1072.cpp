#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Solution{  //可行解
    int index;
    float minDist;
    float average;
};
int main(){
    int n, m, k, ds;
    scanf("%d %d %d %d", &n, &m, &k, &ds);
    //建立邻接矩阵
    vector<vector<int> > E(n+m+1, vector<int>(n+m+1, INT_MAX));
    for (int i=0; i<k; i++){
        char a[5], b[5];  //最多要装1000，字符串大小应>=4
        int u, v, d;
        scanf("%s %s %d", a, b, &d);
        u = a[0]=='G' ? n+atoi(&a[1]) : atoi(a);
        v = b[0]=='G' ? n+atoi(&b[1]) : atoi(b);
        E[u][v] = E[v][u] = d;
    }
    //Dijkstra算法求最短路径
    vector<vector<int> > dist(m+1, vector<int>(n+m+1, INT_MAX));
    for (int i=1; i<=m; i++){
        vector<bool> visited(n+m+1);
        dist[i][n+i] = 0;
        for (int l=1; l<=m+n; l++){
            int minDist = INT_MAX;
            int minI = -1;
            for (int j=1; j<=n+m; j++){
                if (!visited[j] && dist[i][j]<minDist){
                    minDist = dist[i][j];
                    minI = j;
                }
            }
            if (minI == -1){
                break;
            }
            visited[minI] = true;
            for (int j=1; j<=n+m; j++){
                if (!visited[j] && minDist!=INT_MAX && E[minI][j]!=INT_MAX && minDist+E[minI][j]<dist[i][j]){
                    dist[i][j] = minDist + E[minI][j];
                }
            }
        }
    }

    //记录所有可行解
    vector<Solution> S;
    for (int i=1; i<=m; i++){
        float minDist = INT_MAX;
        float sum = 0.0;
        for (int j=1; j<=n; j++){
            if (dist[i][j] > ds){
                minDist = 0;
                break;
            }
            if (dist[i][j] < minDist) {
                minDist = dist[i][j];
            }
            sum += dist[i][j];
        }
        if (minDist > 0){
            S.push_back({i, minDist, sum/n});
        }
    }

    if (S.size() == 0){
        printf("No Solution\n");
    }
    else{
        //找出其中最小距离最远，平均距离最小的第一个
        Solution bestS = S[0];
        for (int i=1; i<S.size(); i++){
            if (S[i].minDist>bestS.minDist || (S[i].minDist==bestS.minDist && S[i].average<bestS.average)){
                bestS = S[i];
            }
        }
        printf("G%d\n%.1f %.1f\n", bestS.index, bestS.minDist, bestS.average);
    }
    return 0;
}
