#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int sum1 = 0;
    for (int i=0; i<n/2; i++){
        sum1 += a[i];
    }
    int sum2 = 0;
    for (int i=n/2; i<n; i++){
        sum2 += a[i];
    }
    cout << n % 2 << " " << sum2 - sum1;
    return 0;
}
