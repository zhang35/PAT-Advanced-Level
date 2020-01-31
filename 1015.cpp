#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n){
    bool ret = true;
    if (n==1){ 
        ret = false;
    }
    for (int i=2; i<=sqrt(n); i++){
        if (n%i==0){
            ret = false;
            break;
        }
    }
    return ret;
}

int main(){
    int n, d;
    cin >> n;
    while (n > 0){
        cin >> d;
        if (!isPrime(n)){
            cout << "No" << endl;
        }
        else {
            vector<int> a(32);
            int len = 0;
            while (n!=0){
                a[len++] = n % d;
                n /= d;
            }
            for (int i=0; i<len; i++){
                n = n * d + a[i];
            }
            if (isPrime(n)){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        cin >> n;
    }
    return 0;
}


