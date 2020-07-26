#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int m = sqrt(n);
    int maxLen = 0;
    int maxI = 0;
    for (int i=2; i<=m; i++){
        int j = i + 1;
        int temp = i;
        while (n % temp == 0){
            temp *= j;
            j++; 
        }
        if (j-i-1 > maxLen){
            maxLen = j - i - 1;
            maxI = i;
        }
    }
    if (maxLen == 0){
        cout << 1 << endl << n;
    }
    else{
        cout << maxLen << endl;
        cout << maxI;
        for (int i=1; i<maxLen; i++){
            cout << "*" << maxI + i;
        }
    }
}
