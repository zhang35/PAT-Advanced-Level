#include <iostream>
#include <vector>
using namespace std;

int main(){
    //初始序列
    vector<int> a(55);
    for (int i=1; i<=54; i++){
        a[i] = i;
    }
    //洗牌序列
    int n;
    cin >> n;
    vector<int> b(55);
    for (int i=1; i<=54; i++){
        cin >> b[i];
    }
    //洗牌
    for (int i=0; i<n; i++){
        vector<int> c(55);
        for (int j=1; j<=54; j++){
            c[b[j]] = a[j];
        }
        a = c;
    }
    //打印牌号 
    string cards = "SHCDJ";
    cout << cards[(a[1]-1)/13] << (a[1]-1)%13+1;
    for (int i=2; i<=54; i++){
        cout << " " << cards[(a[i]-1)/13] << (a[i]-1)%13+1;
    }
    return 0;
}
