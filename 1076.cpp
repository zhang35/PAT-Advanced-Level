#include <iostream>
#include <vector>
using namespace std;

int n, l;
vector<vector<int> > Fans;  //邻接表存储粉丝信息

int bfs(int root){
    vector<int> v;
    v.push_back(root);
    vector<int> visited(n+1);
    visited[root] = true;
    int sum = 0;
    vector<int> newV;
    for (int len=0; len<l; len++){
        newV.clear();
        for (int i=0; i<v.size(); i++){
            for (int j=0; j<Fans[v[i]].size(); j++){
                if (!visited[Fans[v[i]][j]]) {
                    visited[Fans[v[i]][j]] = true;
                    newV.push_back(Fans[v[i]][j]);
                    sum++;
                }
            }
        }
        v = newV;
    }
    return sum;
}
int main(){
    cin >> n >> l;
    Fans.resize(n+1);
    for (int i=1; i<=n; i++){
        int m;
        cin >> m;
        for (int j=0; j<m; j++){
            int user;  //i关注的人
            cin >> user;
            Fans[user].push_back(i);
        }
    }
    int k;
    cin >> k;
    while (k--){
        int user;
        cin >> user;
        cout << bfs(user) << endl;
    }
    return 0;
}
