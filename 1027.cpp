#include <iostream>
using namespace std;

int main(){
    string s = "0123456789ABC";
    cout << "#";
    for (int i=0; i<3; i++){
        int a;
        cin >> a;
        cout << s[a/13] << s[a%13];
    }
    cout << endl;
    return 0;
}
