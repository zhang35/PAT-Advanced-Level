#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    getchar();  //吸收换行符
    vector<string> s(n);
    for (int i=0; i<n; i++){
        getline(cin, s[i]);
    }
    string common = "";

    int j = 1;
    while (1){
        bool flag = true;
        //取s[0]为基准
        if (s[0].size() < j){
            break;
        }
        char ch = s[0][s[0].size()-j];
        //检查剩下的s[1]…s[n-1]
        for (int i=0; i<n; i++){
            if (s[i].size()<j || s[i][s[i].size()-j]!=ch){
                flag = false;
                break;
            }
        }
        if (flag){
            common += ch;
            j++;
        }
        else{
            break;
        }
    }

    if (common.size()==0){
        cout << "nai";
    }
    else{
        for (int i=common.size()-1; i>=0; i--){
            cout << common[i];
        }
    }
    return 0;
}

