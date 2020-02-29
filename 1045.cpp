#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> seq(n+1);  //记录喜欢颜色的位置
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        seq[temp] = i + 1;
    }
    int l;
    cin >> l;
    vector<int> c;  //记录颜色
    for (int i=0; i<l; i++){
        int temp;
        cin >> temp;
        if (seq[temp]!=0){
            c.push_back(temp);
        }
    }
    l = c.size();  //排除不喜欢颜色后的数组大小
    //动态规划，a[i]记录包含第i块颜色时能达到的最大长度
    vector<int> a(l);  
    int totalMax = 0;
    for (int i=0; i<l; i++){
        a[i] = 1;
        int j = i - 1;
        while (j >= 0){
            if (seq[c[j]] <= seq[c[i]]){  //不违反序列规则
                a[i] = max(a[j]+1, a[i]);  //找其中最大的
            }
            while (j>=1 && c[j-1]==c[j]){  //跳过连续相同的颜色
                j--;
            }
            j--;
        }
        totalMax = max(a[i], totalMax);  //记录所有a[i]中最大值
    }
    cout << totalMax << endl;

    return 0;
}

