#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    vector<int> res;
    int maxNum = 0;
    for (int i=0; i<n; i++){
        if (a[i]==b[i] && a[i]>maxNum) res.push_back(a[i]);
        maxNum = max(maxNum, a[i]);
    }

    cout << res.size() << endl;
    if (res.size() > 0){
        cout << res[0];
        for (int i=1; i<res.size(); i++) cout << " " << res[i];
    }
    cout << endl;
    return 0;
}

