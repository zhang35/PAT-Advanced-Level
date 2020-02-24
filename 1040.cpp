#include <iostream>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    int maxNum = 1;
    for (int i=0; i>maxNum/2-1 && i<s.size()-1-maxNum/2; i++){
        //以i为轴
        int num = 1;
        int j = 1;
        while (i-j>=0 && i+j<s.size() && s[i-j]==s[i+j]){
            num += 2;
            j++;
        }
        if (num > maxNum){
            maxNum = num;
        }
        //以i和i+1之间为轴
        num = 0;
        j = 0;
        while (i-j>=0 && i+1+j<s.size() && s[i-j]==s[i+1+j]){
            num += 2;
            j++;
        }
        if (num > maxNum){
            maxNum = num;
        }
    }
    cout << maxNum << endl;
    return 0;
}
