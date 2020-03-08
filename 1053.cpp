#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s;
vector<int> w;
vector<int> path(100);
vector<vector<int> > child(100);

bool cmp(int a, int b){
    return w[a] > w[b];
}
void dfs(int root, int layer, int sum){
    sum += w[root];
    path[layer] = root;
    int k = child[root].size();
    //到达叶子节点
    if (k==0){
        if (sum==s){
            cout << w[0];
            for (int i=1; i<=layer; i++){
                cout << " " << w[path[i]];
            }
            cout << endl;
        }
    }
    else{
        for (int i=0; i<k; i++){
            dfs(child[root][i], layer+1, sum);
        }
    }
}

int main(){
    cin >> n >> m >> s;
    w.resize(n);
    for (int i=0; i<n; i++){
        cin >> w[i];
    }
    for (int i=0; i<m; i++){
        int root, k;
        cin >> root >> k;
        child[root].resize(k);
        for (int j=0; j<k; j++){
            cin >> child[root][j];
        }
        sort(child[root].begin(), child[root].end(), cmp);
    }
    dfs(0, 0, 0);
    return 0;
}
