#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    vector<int> v(n);
    vector<vector<int> > e(n, vector<int>(n, INT_MAX));
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    for (int i=0; i<m; i++){
        int j, k, len;
        cin >> j >> k >> len;
        e[j][k] = len;
        e[k][j] = len;
    }
    //Dijkstra算法
    vector<int> dist(n, INT_MAX);  //从源点出发，到每个节点的最短距离
    dist[c1] = 0;
    vector<int> pathCount(n);  //从源点出发，到每个节点的最短路径数量
    pathCount[c1] = 1;
    vector<int> num(n);  //从源点出发，到每个节点之前的最短路径上能积累的最大救援队数量
    vector<bool> flag(n); //已选入确定最短路径的节点
    for (int count=0; count<n; count++){ //每次添加1个节点，添加所有节点后结束
        int minDist = INT_MAX;
        int minI = -1;
        for (int i=0; i<n; i++) {
            if (!flag[i] && dist[i]<minDist) {
                minDist = dist[i];
                minI = i;
            }
        }
        flag[minI] = true;
        for (int i=0; i<n; i++){ //考虑从新加入节点出发，更新未选节点dist值
            if (!flag[i] && e[minI][i]<INT_MAX){
                int newDist = minDist + e[minI][i];
                if (newDist<dist[i]){  //有新的最短路径
                    dist[i] = newDist;
                    num[i] = num[minI] + v[minI]; //更新沿最短路径上到该点的最大积累数量
                    pathCount[i] = pathCount[minI]; //更新最短路径数量
                }
                else if (newDist==dist[i]){  //有距离相同最短路径
                    num[i] = max(num[i], num[minI] + v[minI]); //取相同最短路径到该点累计数量中较大的
                    pathCount[i] += pathCount[minI];  //注意不是增加1条，而是增加了所有能到新节点的条数
                }
            }
        }
    }
    cout << pathCount[c2] << " " << num[c2] + v[c2] << endl;
    return 0;
}
