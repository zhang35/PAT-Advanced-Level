#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string &s1, string &s2){
    return s1+s2 < s2+s1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i=0; i<n; i++){
        cin >> s[i];
    }

    sort(s.begin(), s.end(), cmp);

    string str = "";
    for (int i=0; i<n; i++){
        str += s[i];
    }
    int pos = 0;
    while (pos<str.size() && str[pos]=='0'){
        pos++;
    }
    if (pos==str.size())  {
        cout << "0";
    }
    while (pos<str.size()){
        cout << str[pos];
        pos++;
    }
    cout << endl;
    return 0;
}
