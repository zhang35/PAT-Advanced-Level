#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<set<int> > v(n);
    for (int i=0; i<n; i++){
        int m;
        scanf("%d", &m);
        for (int j=0; j<m; j++){
            int temp;
            scanf("%d", &temp);
            v[i].insert(temp);
        }
    }
    vector<vector<float> > result(n, vector<float>(n, -1.0));  //结果备忘录
    int k;
    scanf("%d", &k);
    for (int i=0; i<k; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (result[a][b] == -1.0){
            int count = 0;
            for (auto it=v[a].begin(); it!=v[a].end(); ++it){
                if (v[b].find(*it) != v[b].end()){
                    count++;
                }
            }
            result[a][b] = 100.0 * count / (v[a].size() + v[b].size() - count);
            result[b][a] = result[a][b];
        }
        printf("%.1f%%\n", result[a][b]);
    }
    return 0;
}

