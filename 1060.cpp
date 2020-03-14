#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> s(2);  //保存A、B
    vector<string> d(2, "0.");  //保存转换后的结果
    for (int i=0; i<2; i++){
        cin >> s[i];
        int len = s[i].size();
        int dot = 0;  //小数点的位置
        int digit = 0;  //第一个有效位的位置
        while (dot<len && s[i][dot]!='.'){
            dot++;
        }
        while (digit<len && (s[i][digit]<'1' || s[i][digit]>'9')){
            digit++;
        }
        if (digit==len){  //没有有效位，值为0
            digit = dot;
        }
        int exp = dot<digit ? (dot-digit+1) : (dot-digit);
        int count = 0;  //有效位个数
        for (int j=digit; j<len; j++){
            if (s[i][j]>='0' && s[i][j]<='9'){
                d[i] += s[i][j];
                count++;
                if (count==n){
                    break;
                }
            }
        }
        while (count < n){
            d[i] += '0';
            count++;
        }
        d[i] += "*10^";
        d[i] += to_string(exp);
    }
    if (d[0]==d[1]){
        cout << "YES " << d[0] << endl;
    }
    else{
        cout << "NO " << d[0] << " " << d[1] << endl;
    }
    return 0;
}

