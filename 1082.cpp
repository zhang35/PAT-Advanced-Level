#include <iostream>
using namespace std;

string s[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
void printNum(int p){
    int qian = p / 1000;
    int bai = p % 1000 / 100;
    int shi = p % 100 / 10;
    int ge = p % 10;
    if (qian > 0){
        cout << s[qian] << " Qian";
    }
    if (bai > 0){
        if (qian>0){
            cout << " ";
        }
        cout << s[bai] << " Bai";
    }
    else if (qian>0 && (ge>0||shi>0)){
        cout << " ling";
    }
    if (shi > 0){
        if (qian>0 || bai>0){
            cout << " ";
        }
        cout << s[shi] << " Shi";
    }
    else if ((qian>0||bai>0) && ge>0){
        cout << " ling";
    }
    if (ge > 0){
        if (qian>0 || bai>0 || shi>0){
            cout << " ";
        }
        cout << s[ge];
    }
}
int main(){
    long long n;
    cin >> n;
    if (n == 0){
        cout << "ling";
        return 0;
    }
    if (n < 0){
        n = -n;
        cout << "Fu ";
    }
    int p1 = n / 100000000;
    int p2 = n / 10000 % 10000;
    int p3 = n % 10000;
    if (p1 != 0){
        printNum(p1);
        cout << " Yi";
    }
    if (p2 != 0){
        if (p1!=0){
            cout << " ";
            if (p2 < 1000){
                cout << "ling ";
            }
        }
        printNum(p2);
        cout << " Wan";
    }
    if (p3 != 0){
        if(p1!=0 || p2!=0){
            cout << " ";
            if (p3 < 1000){
                cout << "ling ";
            }
        }
        printNum(p3);
    }
    return 0;
}
