#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    string s3 = "";
    int i = 0;
    int j = 0;
    while (i<s1.size() && j<s2.size()){
        if (s1[i]==s2[j]){
            j++;
        }
        else if (s3.find(toupper(s1[i]))==string::npos){
            s3 += toupper(s1[i]);
        }
        i++;
    }
    while (i < s1.size()){
        if (s3.find(toupper(s1[i]))==string::npos){
            s3 += toupper(s1[i]);
        }
        i++;
    }
    cout << s3;
    return 0;
}
