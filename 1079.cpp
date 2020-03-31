#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int> > e;
vector<int> num;
double n, p, r;
double sum = 0.0;

void dfs(int root, int layer){
    if (e[root].size()==0){
        sum += (num[root] * pow(r, layer));
        return;
    }
    for (int i=0; i<e[root].size(); i++){
        dfs(e[root][i], layer+1);
    }
}
int main(){
    cin >> n >> p >> r;
    e.resize(n);
    num.resize(n);
    r = (1 + r/100);
    for (int i=0; i<n; i++){
        int k;
        cin >> k;
        if (k==0){
            cin >> num[i];
        }
        while (k--){
            int temp;
            cin >> temp;
            e[i].push_back(temp);
        }
    }
    dfs(0, 0);
    printf("%.1lf\n", sum * p);
    return 0;
}
