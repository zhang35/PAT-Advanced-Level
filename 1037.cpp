#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m;
    vector<int> a(m);
    for (int i=0; i<m; i++){
        cin >> a[i];
    }
    cin >> n;
    vector<int> b(n);
    for (int i=0; i<n; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long sum = 0;
    for (int i=0; i<m && i<n; i++){
        if (a[i]<0 && b[i]<0){
            sum += (a[i] * b[i]);
        }
        else{
            break;
        }
    }
    for (int i=m-1, j=n-1; i>=0&&j>=0; i--, j--){
        if (a[i]>0 && b[j]>0){
            sum += (a[i] * b[j]);
        }
        else{
            break;
        }
    }
    cout << sum << endl;
    return 0;
}

