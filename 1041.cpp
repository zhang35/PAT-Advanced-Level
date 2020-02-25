#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> m;
    for (int i=0; i<n; i++){
        cin >> a[i];
        m[a[i]]++;
    }
    int i = 0;
    while (i < a.size()){
        if (m[a[i]]==1){
            cout << a[i] << endl;
            break;
        }
        i++;
    }
    if (i==a.size()){
        cout << "None" << endl;
    }
    return 0;
}
