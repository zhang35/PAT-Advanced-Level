#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    //n1<=N+2-2*n1 => n1<=(n+2)/3
    int n1 = (n+2) / 3;
    int n2 = n - 2 * n1 + 2;
    for (int i=0; i<n1-1; i++){
        cout << s[i];
        for (int j=0; j<n2-2; j++){
            cout << " ";
        }
        cout << s[n-1-i] << endl;
    }
    for (int i=0; i<n2; i++){
        cout << s[n1-1+i];
    }
    cout << endl;
    return 0;
}
