#include <iostream>
using namespace std;

bool isPalin(string s){
    for (int i=0; i<s.size()/2; i++){
        if (s[i]!=s[s.size()-1-i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s;
    int k;
    cin >> s >> k;
    
    int i = 0;
    while (i<k){
        if (isPalin(s)){
            cout << s << "\n" << i << endl;
            break;
        }
        string ans = "";
        int addition = 0;
        int n = s.size();
        for (int j=0; j<n; j++){
            char temp = (s[j] + s[n-1-j] + addition - '0');
            if (temp > '9'){
                temp -= 10;
                addition = 1;
            }
            else {
                addition = 0;
            }
            ans = temp + ans;
        }
        if (addition > 0){
            ans = '1' + ans;
        }
        s = ans;
        i++;
    }
    if (i==k){
        cout << s << "\n" << i << endl;
    }
    return 0;
}
