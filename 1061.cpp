#include <iostream>
#include <cctype>
using namespace std;

const string day[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main(){
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int i = 0;
    while (i<s1.size()){
        if (s1[i]==s2[i] && isupper(s1[i]) && s1[i]<='G'){
            cout << day[s1[i]-'A'] << " ";
            break;
        }
        i++;
    }
    i++;
    while (i<s1.size()){
        if (s1[i]==s2[i]){
            if (isupper(s1[i]) && s1[i]<='N'){
                printf("%02d:", s1[i] - 'A' + 10);
                break;
            }
            else if (isdigit(s1[i])){
                printf("%02d:", s1[i] - '0');
                break;
            }
        }
        i++;
    }
    for (i=0; i<s3.size(); i++){
        if (s3[i]==s4[i] && isalpha(s3[i])){
            printf("%02d", i);
            break;
        }
    }
    return 0;
}

