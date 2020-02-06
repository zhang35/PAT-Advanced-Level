#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > E;
void DFS(int m, vector<bool> & visited, int depth, int *maxDepth){
    depth++;
    if (depth > *maxDepth){
        *maxDepth = depth; 
    }
    visited[m] = true;
    for (int i=0; i<E[m].size(); i++){
        if (!visited[E[m][i]]){
            DFS(E[m][i], visited, depth, maxDepth);
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

    vector<int> D(n+1);  //depth
    vector<bool> visited(n+1);

    int depth = 0;
    DFS(1, visited, 0, &depth);
    D[1] = depth;

    int component = 1;
    for (int i=2; i<=n; i++){
        if (!visited[i]) {
            DFS(i, visited, 0, &depth);
            component++;
        }
    }

    if (component > 1){
        cout <<  "Error: " << component << " components" << endl;
    }
    else {
        int maxDepth = D[1];
        for (int i=2; i<=n; i++){
            fill(visited.begin(), visited.end(), false);
            depth = 0;
            DFS(i, visited, 0, &depth);
            D[i] = depth;
            if (depth > maxDepth){
                maxDepth = depth;
            }
        }
        for (int i=1; i<=n; i++){
            if (D[i]==maxDepth){
                cout << i << endl;
            }
        }
    }
    return 0;
}
