#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    if (s[0]=='-'){
        cout << '-';
    }
    int pos = s.find('E');
    int exp = stoi(s.substr(pos+1));
    if (exp >= 0){
        cout << s[1];
        int i = 3;
        while (i<pos && exp--){
            cout << s[i];
            i++;
        }
        if (i==pos){
            while (exp--){
                cout << 0;
            }
        }
        else{
            cout << '.';
            while (i<pos){
                cout << s[i];
                i++;
            }
        }
    }
    else{
        for (int i=0; i<-exp; i++){
            cout << 0;
            if (i==0){
                cout << '.';
            }
        }
        cout << s[1];
        for (int i=3; i<pos; i++){
            cout << s[i];
        }
    }
    return 0;
}
