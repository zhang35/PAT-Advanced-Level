#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> c(n);
    c[0] = a[0];
    int maxSum = c[0];
    int r = 0;
    for (int i=1; i<n; i++){
        if (c[i-1]>0){
            c[i] = c[i-1] + a[i];
        }
        else {
            c[i] = a[i];
        }
        if (c[i] > maxSum){
            maxSum = c[i];
            r = i;
        }
    }
    if (maxSum < 0){
        cout << 0 << " " << a[0] << " " << a[n-1] << endl;
    }
    else {
        cout << maxSum << " ";
        int l = r;
        while (maxSum!=0){
            maxSum -= a[l];
            l--;
        }
        while (l>=0 && c[l]==0){
            int tempSum = 0;
            do {
                tempSum += a[l];
                l--;
            }while (tempSum!=0);
        }
        cout << a[l+1] << " " << a[r] << endl;
    }
    return 0;
}

