#include <iostream>
#include <cctype>
#include <sstream>
#include <unordered_map>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    for (int i=0; i<s.size(); i++){
        if (isalnum(s[i])){
            s[i] = tolower(s[i]);
        }
        else{
            s[i] = ' ';
        }
    }
    unordered_map<string, int> mm;
    stringstream ss(s);
    while (ss >> s){
        mm[s]++;
    }
    int maxNum = 0;
    for (auto it=mm.begin(); it!=mm.end(); ++it){
        if (it->second > maxNum){
            s = it->first;
            maxNum = it->second;
        }
    }
    cout << s << " " << maxNum << endl;
    return 0;
}

