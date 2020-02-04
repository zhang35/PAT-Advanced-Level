#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, b;
    cin >> n >> b;
    vector<int> a;
    do{
        a.push_back(n % b);  //倒序存储，不影响判断回文数
        n /= b;
    }while (n!=0);
    int len = a.size();
    bool isPalin = true;
    for (int i=0; i<len/2; i++){
        if (a[i] != a[len-1-i]){
            isPalin = false;
            break;
        }
    }
    if (isPalin){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    cout << a[len-1];
    for (int i=len-2; i>=0; i--){
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}
