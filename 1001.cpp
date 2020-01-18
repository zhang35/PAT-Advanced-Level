#include <iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    a += b;
    if (a<0){
        cout << "-";
        a *= -1;
    }
    string s = to_string(a);
    int n = s.size();
    for (int i=0; i<n; i++){
        cout << s[i];
        if (i!=n-1 && (n-1-i)%3==0){
            cout << ",";
        }
    }
    cout << endl;
    return 0;
}
