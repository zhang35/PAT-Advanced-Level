#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    queue<pair<int, int> > que;
    que.push({0, n-1});
    while (!que.empty()){
        pair<int, int> p = que.front();
        que.pop();
        int m = p.second - p.first + 1;  //总节点数
        if (m < 1){
            continue;
        }
        if (m < n){
            cout << " ";
        }
        if (m==1){
            cout << v[p.first];
        }
        else{
            //min{左子树满树时节点数, 总节点数-(右子树节点数+1)}
            int root = p.first + min(exp2((int)log2(m)) - 1, m - exp2((int)log2(m) - 1));  
            cout << v[root];
            que.push({p.first, root-1});
            que.push({root+1, p.second});
        }
    }
    cout << endl;
    return 0;
}

