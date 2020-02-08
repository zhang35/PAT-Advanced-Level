#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int addition = 0;
    string ans = "";  //倒序存储结果
    for (int i=s.size()-1; i>=0; i--){
        int temp = (s[i] - 48) * 2 + addition;
        if (temp >= 10){
            addition = 1;
            temp -= 10;
        }
        else {
            addition = 0;
        }
        ans += (temp + 48);
    }
    bool found = false;
    if (addition > 0){
        ans += '1';
    }
    else{
        for (int i=0; i<ans.size(); i++){
            found = false;
            for (int j=0; j<s.size(); j++){
                if (ans[i] == s[j]){
                    s[j] = '*';
                    found = true; 
                    break;
                }
            }
            if (!found){
                break;
            }
        }
    }
    if (found){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    for (int i=ans.size()-1; i>=0; i--){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
