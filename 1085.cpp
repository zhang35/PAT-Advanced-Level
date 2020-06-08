#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, p;
    cin >> n >> p;
    vector<long long> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int m = 0;
    int i = 0;
    int j = 0;
    while (n - i > m){
        while (a[j]<=a[i]*p && j<n){
            j++;
        }
        if (j - i > m){
            m = j - i;
        }
        i++;
    }
    cout << m << endl;
    return 0;
}
