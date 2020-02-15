#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node{
    int v;  //index
    int d;  //dist
    int w;  //weight
};

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<Node> > E(n);  //邻接表
    for (int i=0; i<m; i++){
        int u, v, d, w;
        cin >> u >> v >> d >> w;
        E[u].push_back({v, d, w});
        E[v].push_back({u, d, w});
    }

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n);
    vector<int> pre(n, -1);
    vector<int> weight(n);
    dist[s] = 0;
    for (int i=0; i<n; i++){
        int minDist = INT_MAX;
        int k = -1;
        for (int j=0; j<n; j++){
            if (!visited[j] && dist[j]<minDist){
                minDist = dist[j];
                k = j;
            }
        }

        visited[k] = true;

        for (int j=0; j<E[k].size(); j++){
            Node cur = E[k][j];
            if (!visited[cur.v]){
                if (minDist + cur.d < dist[cur.v]){
                    dist[cur.v] = minDist + cur.d; 
                    weight[cur.v] = weight[k] + cur.w;
                    pre[cur.v] = k;
                }
                else if(minDist + cur.d == dist[cur.v]){
                    if (weight[k]+cur.w < weight[cur.v]){
                        weight[cur.v] = weight[k] + cur.w;
                        pre[cur.v] = k;
                    }
                }
            }
        }
    }
    vector<int> path;
    for (int i=t; i!=-1; i=pre[i]){
        path.push_back(i);
    }
    for (int i=path.size()-1; i>=0; i--){
        cout << path[i] << " ";
    }
    cout << dist[t] << " " << weight[t] << endl;
}
