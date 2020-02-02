#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct C{  //顾客信息
    int arr;  //到达时间
    float dur;  //所需时间
};

bool cmp(C c1, C c2){
    return c1.arr < c2.arr;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<C> wait;
    for (int i=0; i<n; i++){
        int h, m, s;       
        float dur;
        scanf("%d:%d:%d %f", &h, &m, &s, &dur);
        int arr = 3600 * h + 60 * m + s;  //时间统一转换为秒
        if (arr <= 61200){  //3600 * 17 
            wait.push_back({arr, dur * 60});  //加入早于17:00到达的顾客
        } 
    }
    int len = wait.size();
    sort(wait.begin(), wait.end(), cmp);

    //处理过程
    float sum = 0;  //总等待时间
    vector<int> window(k, 28800);  ////3600 * 8，每个窗口上个顾客结束时
    for (int i=0; i<len; i++){
        //找出当前结束时间最早的窗口
        int minT = window[0];
        int minI = 0;
        for (int j=1; j<k; j++) {
            int t = window[j];
            if (t < minT){
                minT = t;
                minI = j;
            }
        }
        if (window[minI]==minT){
            if (wait[i].arr < window[minI]){  //若顾客到的比上个结束时间早
                sum += (window[minI] - wait[i].arr);
                window[minI] += wait[i].dur;
            }
            else {
                window[minI] = wait[i].arr + wait[i].dur;
            }
        }
    }
    if (len==0){
        printf("0.0\n");
        return 0;
    }
    else {
        printf("%.1f\n", sum / len / 60.0);
    }

    return 0;
}



