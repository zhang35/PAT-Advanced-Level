#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string a;
    cin >> a;

    int sum = 0;
    int n = a.size();
    for (int i=0; i<n; i++){
        int A1 = i>0 ? stoi(a.substr(0, i)) : 0;
        int A2 = i<n-1 ? stoi(a.substr(i+1, n-1-i)) : 0;
        if (a[i]<'1'){
            sum += (A1 * pow(10, n-i-1));
        }
        else if(a[i]=='1'){
            sum += (A1 * pow(10, n-i-1) + A2 + 1);
        }
        else{
            sum += ((A1+1) * pow(10, n-i-1));
        }
    }
    cout << sum << endl;
    return 0;
}

