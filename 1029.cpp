#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int> > a(2);
    for (int i=0; i<2; i++){
        int n;
        cin >> n;
        a[i].resize(n);
        for (int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }
    int i = 0;
    int j = 0;
    int mid = (a[0].size() + a[1].size() - 1) / 2;
    int count = -1;
    while (i<a[0].size() && j<a[1].size()){
        count++;
        if (a[0][i] < a[1][j]){
            if (count==mid){
                cout << a[0][i];
                break;
            }
            i++;
        }
        else{
            if (count==mid){
                cout << a[1][j];
                break;
            }
            j++;
        }
    }

    if (count < mid){
        count++;
        if (i==a[0].size()){
            while(count<mid){
                count++;
                j++;
            }
            cout << a[1][j];
        }
        else if(j==a[1].size()){
            while(count<mid){
                count++;
                i++;
            }
            cout << a[0][i];
        }
    }
    cout << endl;
    return 0;
}

