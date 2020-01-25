#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int up = 0;
    int down = 0;
    int last = 0;
    for (int i=0; i<n; i++){
        int k;
        cin >> k;
        if (k > last){
            up += (k - last);
        }
        else {
            down += (last - k);
        }
        last = k;
    }
    
    int sum = n * 5 + up * 6 + down * 4;
    cout << sum << endl;
    return 0;
}
