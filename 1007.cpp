#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    bool isAllNegtive = true;
    for (int i=0; i<n; i++){
        cin >> v[i];
        if (v[i] >= 0){
            isAllNegtive = false;
        }
    }

    if (isAllNegtive){
        cout << 0 << " " << v[0] << " " << v[n-1];
    }
    else {
        int maxSum = 0;
        int l = -1;
        int r = -1;
        for (int i=0; i<n; i++){
            int sum = v[i];
            if (maxSum < sum){
                l = i;
                r = i;
                maxSum = sum;
            }
            int last = sum;
            for (int j=i+1; j<n; j++){
                sum += v[j];
                if (last < sum){
                    last = sum;
                    if (maxSum < sum){
                        l = i;
                        r = j;
                        maxSum = sum;
                    }
                }
            }
        }
        cout << maxSum << " " << v[l] << " " << v[r];
    }

    cout << endl;
    return 0;
}
