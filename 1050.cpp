#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    vector<bool> a(128);
    for (int i=0; i<s2.size(); i++){
        a[s2[i]] = true;
    }
    for (int i=0; i<s1.size(); i++){
        if (!a[s1[i]]){
            cout << s1[i];
        }
    }
    return 0;
}

