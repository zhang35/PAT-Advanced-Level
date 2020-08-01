#include <iostream>
#include <vector>
using namespace std;

#define MAXINT 0x3f3f3f3f

void printPath(vector<int> &path){
    int i = path.size() - 1;
    cout << path[i--];
    while (i >= 0){
        cout << " -> " << path[i--];
    }
    cout << endl;
}

void dfs(vector<vector<int> > &pre, vector<vector<int> > &w, int root, int sum, int &minSum, vector<int> path, vector<int> &minPath){
    path.push_back(root);
    if (pre[root].size()==0) {  //到达叶子
        if (sum < minSum){
            minSum = sum;
            minPath = path;
        }
        return;
    }
    for (int i=0; i<pre[root].size(); i++){
        dfs(pre, w, pre[root][i], sum + w[pre[root][i]][root], minSum, path, minPath);
    }
}

void Dijkstra(int src, vector<vector<int> > &w, vector<int> &dist, vector<vector<int> > &pre){
    vector<bool> visited(dist.size());
    dist[src] = 0;
    for (int i=0; i<dist.size(); i++){
        int minDist = MAXINT;
        int minI = -1;
        for (int j=0; j<dist.size(); j++){
            if (!visited[j] && dist[j]<minDist){
                minDist = dist[j];
                minI = j;
            }
        }
        visited[minI] = true;
        for (int j=0; j<dist.size(); j++){
            if (!visited[j]){
                if (minDist + w[minI][j] < dist[j]){
                    pre[j].clear();
                    pre[j].push_back(minI);
                    dist[j] = minDist + w[minI][j];
                }
                else if (minDist + w[minI][j] == dist[j]){
                    pre[j].push_back(minI);
                }
            }
        }
    }
}

int main() {
    int n, m, src, dst;
    cin >> n >> m;
    vector<vector<int> > len(n, vector<int>(n, MAXINT));
    vector<vector<int> > time(n, vector<int>(n, MAXINT));
    for (int i=0; i<m; i++){
        int u, v, flag, l, t;
        cin >> u >> v >> flag >> l >> t;
        len[u][v] = l;
        time[u][v] = t;
        if (!flag){
            len[v][u] = l;
            time[v][u] = t;
        }
    }
    cin >> src >> dst;
    
    //Dijkstra找最短距离路径
    vector<int> distL(n, MAXINT);
    vector<vector<int> > preL(n);
    Dijkstra(src, len, distL, preL);
    //dfs找最短路径中时间最小路径
    int minL = MAXINT;
    vector<int> minPathL;
    vector<int> path;
    dfs(preL, time, dst, 0, minL, path, minPathL);
    
    //Dijkstra找最短时间路径
    vector<int> distT(n, MAXINT);
    vector<vector<int> > preT(n);
    Dijkstra(src, time, distT, preT);
    //dfs找最短路径中节点数最小的
    int minT = MAXINT;
    vector<int> minPathT;
    path.clear();
    vector<vector<int> > nodes(n, vector<int>(n, 1));  //经过节点数量，统一为1
    dfs(preT, nodes, dst, 0, minT, path, minPathT);

    cout << "Distance = " << distL[dst];
    if (minPathL == minPathT)
        cout << "; ";
    else{
        cout << ": ";
        printPath(minPathL);
    }
    cout << "Time = " << distT[dst] << ": ";
    printPath(minPathT);
    return 0;
}
