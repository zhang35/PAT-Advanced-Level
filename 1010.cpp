#include <iostream>
#include <cctype>
using namespace std;

long long str2int(string s, long long radix){
    long long value = 0;
    long long multiplier = 1;
    for (int i=s.size()-1; i>=0; i--){
        int d = isalpha(s[i]) ? s[i]-87 : s[i]-48;
        value += (d * multiplier);
        multiplier *= radix;
    }
    return value;
}

int main(){
    string n1, n2;
    int tag;
    long long radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag==2){
        swap(n1, n2);
    }
    long long value = str2int(n1, radix);
    long long l = 1;
    for (int i=0; i<n2.size(); i++){
        int d = isalpha(n2[i]) ? n2[i]-87 : n2[i]-48;
        if (d >= l){
            l = d + 1;
        }
    }
    long long r = value>l ? value : l;
    long long mid = 1;
    bool flag = false;
    while (l <= r){
        mid = (l + r) / 2;
        long long temp = str2int(n2, mid);
        if (temp == value){
            flag = true;
            break;
        }
        else if (temp>value || temp<0){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    if (flag){
        cout << mid << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    return 0;
}
