#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    for (int i=0; i<n; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        bool ret = false;
        if ((a^b)<0 || (a&b)==0){  //a、b异号，或有一个为0
            if (a + b > c) {
                ret = true;
            }
        }
        else{  //a、b同号
            if (a>0 && b>0){
                if (c <= 0){
                    ret = true; 
                }
                else if (a > c - b){
                        ret = true; 
                }
            }
            else if(c<0 && a>c-b){
                ret = true;
            }
        }
        cout << "Case #" << i + 1;
        if (ret){
            cout << ": true" << endl;;
        }
        else{
            cout << ": false" << endl;;
        }
    }
    return 0;
}


