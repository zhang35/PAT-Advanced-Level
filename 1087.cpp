#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

unordered_map<string, int> mp;  //城市名-序号
vector<string> mp1;  //序号-城市名
vector<int> happy;  //快乐值
vector<int> minPath;
int maxHappy = 0;
int pathCount = 0;

void dfs(int cur, vector<vector<int> > &pre, vector<int> path, int h){
    if (cur==0){
        pathCount++;
        if (h > maxHappy){
            maxHappy = h;
            minPath = path;
        }
        else if (h==maxHappy){
            if (path.size() < minPath.size()){
                minPath = path; 
            }
        }
        return;
    }

    h += happy[cur];
    path.push_back(cur);

    for (int i=0; i<pre[cur].size(); i++){
        dfs(pre[cur][i], pre, path, h);
    }
}

int main(){
    int n, k;
    string name;

    cin >> n >> k >> name;

    vector<vector<int> > g(n, vector<int>(n, INT_MAX));  //邻接矩阵
    vector<vector<int> > pre(n);  //最短路径前趋节点,pre[i][j]表示i的第j个前趋节点
    vector<int> dist(n);  //最小距离
    happy.resize(n);

    int count = 0;
    dist[0] = 0;
    happy[0] = 0;
    mp[name] = count++;
    mp1.push_back(name);

    for (int i=1; i<n; i++){
        int h;
        cin >> name >> h;
        dist[count] = INT_MAX;
        happy[count] = h;
        mp[name] = count++;
        mp1.push_back(name);
    }

    for (int i=0; i<k; i++){
        string c1, c2;
        int cost;
        cin >> c1 >> c2 >> cost;
        g[mp[c1]][mp[c2]] = g[mp[c2]][mp[c1]] = cost;
    }

    vector<bool> visited(n);
    for (int i=0; i<n; i++) {
        int minD = INT_MAX;
        int minI = -1;
        for (int j=0; j<n; j++){
            if (!visited[j] && dist[j]<minD){
                minD = dist[j];
                minI = j;
            }
        }
        visited[minI] = true;
        for (int j=0; j<n; j++){
            if (!visited[j] && g[minI][j]!=INT_MAX) {
                if (g[minI][j]+dist[minI] < dist[j]){
                    dist[j] = g[minI][j]+dist[minI];
                    pre[j].clear();
                    pre[j].push_back(minI);
                }
                else if (g[minI][j]+dist[minI] == dist[j]){
                    pre[j].push_back(minI);
                }
            }
        }
    }

    vector<int> path;
    dfs(mp["ROM"], pre, path, 0);

    cout << pathCount << " " << dist[mp["ROM"]] << " " << maxHappy << " " << maxHappy/minPath.size() << endl;
    cout << mp1[0];
    for (int i=minPath.size()-1; i>=0; i--){
        cout << "->" << mp1[minPath[i]];
    }
    cout << endl;
    return 0;
}
