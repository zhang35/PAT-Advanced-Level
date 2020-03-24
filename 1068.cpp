#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a1, int &a2){
    return a1 > a2;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a.begin()+1, a.end(), cmp);
    //动态规划，第i轮的F[j]表示用前i个币在总价值不超过j时能达到的最大价值
    vector<int> F(m+1);
    //记录选择
    vector<vector<int> > B(n+1, vector<int>(m+1));
    for (int i=1; i<=n; i++) {
        for (int j=m; j>=1; j--){
            if (j>=a[i] && F[j-a[i]]+a[i] >= F[j]) {
                F[j] = F[j-a[i]] + a[i];
                B[i][j] = i;
            }
            else{
                B[i][j] = B[i-1][j];
            }
        }
    }
    if (F[m] != m){
        cout << "No Solution";
    }
    else{
        int v = a[B[n][m]];
        cout << v;
        while (1){
            n = B[n][m] - 1;
            m -= v;
            if (m==0){
                break;
            }
            v = a[B[n][m]];  //本轮选的数
            cout << " " << v;
        }
    }
    return 0;
}

