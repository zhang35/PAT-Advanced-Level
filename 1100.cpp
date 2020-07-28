#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> mar1 = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> mar2 = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int findIndex(string s, vector<string> &mar){
    for (int i=0; i<mar.size(); i++){
        if (s==mar[i]) return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    getchar();  //吸收换行符
    string s;
    for (int i=0; i<n; i++){
        getline(cin, s);
        if (isdigit(s[0])){
            int k = stoi(s);
            if (k > 12){
                cout << mar2[k/13];
                if (k%13!=0) cout <<  " " << mar1[k%13];
            }
            else{
                cout << mar1[k];
            }
        }
        else{
            int num;
            if (s.size()>4){
                num = findIndex(s.substr(0,3), mar2) * 13 + findIndex(s.substr(4, 3), mar1);
            }
            else{
                num = findIndex(s, mar1);
                if (num==-1) num = findIndex(s, mar2) * 13;
            }
            cout << num;
        }
        cout << endl;
    }
    return 0;
}

