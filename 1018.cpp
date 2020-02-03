#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int cmax, n, sp, m;
    cin >> cmax >> n >> sp >> m;
    n++;  //加上源点
    vector<int> C(n);  //自行车数
    for (int i=1; i<n; i++){
        cin >> C[i];
    }
    vector<vector<int> > T(n, vector<int>(n, INT_MAX));  //邻接矩阵
    for (int i=0; i<m; i++){
        int j, k, len;
        cin >> j >> k >> len;
        T[j][k] = len;
        T[k][j] = len;
    }

    //Dijkstra算法
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    vector<bool> flag(n);  //已考察节点
    vector<vector<vector <int> > > path(n);  //path[i][j][k]是到节点i的第j条最短路径的第k个节点
    vector<int> temp = {0};
    path[0].push_back(temp);
    for (int i=0; i<n; i++){
        int minDist = INT_MAX;
        int minI = -1;
        for (int j=0; j<n; j++){
            if (!flag[j] && dist[j]<minDist){
                minDist = dist[j];
                minI = j;
            }
        }
        flag[minI] = true;
        //更新dist
        for (int j=0; j<n; j++){
            if (!flag[j] && T[minI][j]!=INT_MAX){  //必须判断是否存在路径,否则INT_MAX+1即为负数。
                int newDist = minDist + T[minI][j];
                if (newDist < dist[j]){
                    path[j] = path[minI];
                    for (int k=0; k<path[j].size(); k++){
                        path[j][k].push_back(j);
                    }
                    dist[j] = newDist;
                }
                else if (newDist == dist[j]){
                    for (int k=0; k<path[minI].size(); k++){
                        vector<int> temp = path[minI][k];
                        temp.push_back(j);
                        path[j].push_back(temp);
                    }
                }
            }
        }
    }
    
    int minNeed = INT_MAX;
    int minBack = INT_MAX;
    int minI = -1;
    int perfect = cmax / 2;
    for (int i=0; i<path[sp].size(); i++){
        int need = 0;
        int surplus = 0;
        for (int j=1; j<path[sp][i].size(); j++){
            int num = C[path[sp][i][j]] + surplus;
            if (num <= perfect){
                need += (perfect - num);
                surplus = 0;
            }
            else {
                surplus = num - perfect;
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minBack = surplus;
            minI = i;
        }
        else if (need==minNeed){
            if (surplus < minBack){
                minBack = surplus;
                minI = i;
            }
        }
    }
    cout << minNeed << " 0";
    for (int i=1; i<path[sp][minI].size(); i++){
        cout << "->" << path[sp][minI][i];
    }
    cout << " " << minBack << endl;
    return 0;
}




