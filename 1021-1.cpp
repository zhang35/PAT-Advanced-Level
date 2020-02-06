#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int> > E;
set<int> S;
int maxDepth = 0;
void DFS(int m, vector<bool> & visited, int depth){
    depth++;
    if (depth > maxDepth){
        maxDepth = depth; 
        S.clear();
        S.insert(m);
    }
    else if (depth == maxDepth){
        S.insert(m);
    }
    visited[m] = true;
    for (int i=0; i<E[m].size(); i++){
        if (!visited[E[m][i]]){
            DFS(E[m][i], visited, depth);
        }
    }
    return;
}
int main(){
    int n;
    cin >> n;
    E.resize(n+1);
    //稀疏矩阵，需用邻接表存储边，否则内存超限
    for (int i=1; i<n; i++){
        int j, k;
        cin >> j >> k;
        E[j].push_back(k);
        E[k].push_back(j);  
    }
    vector<bool> visited(n+1);
    DFS(1, visited, 0);

    //判断有几个连通分支
    int component = 1;
    for (int i=2; i<=n; i++){
        if (!visited[i]) {
            DFS(i, visited, 0);
            component++;
        }
    }

    if (component > 1){
        cout <<  "Error: " << component << " components" << endl;
    }
    else {
        fill(visited.begin(), visited.end(), false);
        set<int> oldSet = S;
        int k = *S.begin();
        S.clear();
        maxDepth = 0;
        DFS(k, visited, 0);
        for (auto it=oldSet.begin(); it!=oldSet.end(); ++it){
            S.insert(*it);
        }
        for (auto it=S.begin(); it!=S.end(); ++it){
            cout << *it << endl;
        }
    }
    return 0;
}
