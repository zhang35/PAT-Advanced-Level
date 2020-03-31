#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if (n == 1) {
        return false;
    }
    for (int i=2; i<=sqrt(n); i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int m, n;
    cin >> m >> n;
    while (!isPrime(m)){
        m++;
    }
    vector<bool> exist(m);
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        int h = a % m;
        if (i > 0){
            cout << " ";
        }
      //平方探测法避免冲突
        bool flag = false;  //true:找到空位置； false:未找到
        for (int step=0; step<m; step++){
            h = (a + step * step) % m;
            if (!exist[h]){
                flag = true;
                break;
            }
        }
        if (flag){
            exist[h] = true;
            cout << h;
        }
        else{
            cout << "-";
        }
    }
    return 0;
}
