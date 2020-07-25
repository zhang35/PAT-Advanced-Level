#include <iostream> 
using namespace std; 

int main() { 
    string s;
    cin >> s;
    long long p = 0;
    long long pa = 0;
    long long pat = 0;
    for (int i=0; i<s.size(); i++){
        if (s[i]=='P') p++;
        if (s[i]=='A') pa += p;
        if (s[i]=='T') pat += pa;
    }
    cout << pat << endl;
    return 0;
}
