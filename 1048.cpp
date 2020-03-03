#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coin(n);
    for (int i=0; i<n; i++){
        cin >> coin[i];
    }
    sort(coin.begin(), coin.end());
    for (int i=0; i<n-1; i++){
        if (binary_search(coin.begin()+i+1, coin.end(), m-coin[i])){
            cout << coin[i] << " " << m - coin[i] << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}

