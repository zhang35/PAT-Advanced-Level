#include <iostream>
#include <cctype>
using namespace std;
//将字符串存储的数字s，按radix进制转化为10进制
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
    if (tag==2){//统一把已知进制的数视为n1，待求解的数视为n2
        swap(n1, n2);
    }
    long long value = str2int(n1, radix);//求出n1的十进制值
    //初始化n2 radix的下界，为各位最大值+1，可能取到1
    long long l = 1;
    for (int i=0; i<n2.size(); i++){
        int d = isalpha(n2[i]) ? n2[i]-87 : n2[i]-48;
        if (d >= l){
            l = d + 1;
        }
    }
    //初始化n2 radix的上界，最大为value；当n1只有1位数字时，value可能比下界小，此时应取下界的值
    long long r = value>l ? value : l;
    //二分法找n2的radix
    long long mid = 1;
    bool flag = false;
    while (l <= r){
        mid = (l + r) / 2;
        long long temp = str2int(n2, mid);
        if (temp == value){
            flag = true;
            break;
        }
        else if (temp>value || temp<0){ //mid值很大时，返回的temp可能溢出，变成负数
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
