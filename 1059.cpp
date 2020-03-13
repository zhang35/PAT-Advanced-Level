#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> prime;  //素数备忘录
vector<int> factor;  //素因数
bool isPrime(int n){
    for (int i=2; i<=sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
void divide(int n){
    if (n < 2){
        return;
    }
    int len = prime.size();
    int m = 0;
    for (int i=0; i<len; i++){
        if (n % prime[i] == 0) {
            m = n / prime[i];
            factor.push_back(prime[i]);
            break;
        }
    }
    if (m==0){  //n不能被备忘录中的素数整除，继续考察根N范围内是否有因数，扩展素数备忘录
        for (int i=prime[len-1]+1; i<=sqrt(n); i++){
            if (isPrime(i)){
                prime.push_back(i);
                if (n % i == 0){
                    m = n / i;
                    factor.push_back(i);
                    break;
                }
            }
        }
    }
    if (m==0){  //n确定是素数
        factor.push_back(n);
        return;
    }
    else {
        divide(m);
    }
}
int main(){
    prime.push_back(2);
    int n;
    cin >> n;
    cout << n << "=";
    if (n==1){
        cout << "1";
    }
    else{
        divide(n);
        int i = 0;
        while (i<factor.size()){
            if (i > 0){
                cout << "*";
            }
            cout << factor[i];
            int j = i + 1;
            while (j<factor.size() && factor[j]==factor[i]){
                j++;
            }
            int k = j - i;
            if (k > 1){
                cout << "^" << k;
            }
            i = j;
        }
    }
    return 0;
}
