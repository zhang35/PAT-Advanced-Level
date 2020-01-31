#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct C{  //顾客信息
    int id;  //编号
    int t;  //所需时间
};

int main(){
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<queue<C> > window(n);
    //队列区域
    int count = 1;
    for (int i=0; i<m && count<=k; i++){
        for (int j=0; j<n && count<=k; j++){
            int t;
            cin >> t;
            window[j].push({count, t});
            count++;
        }
    }
    //等待区域
    queue<C> wait; 
    while (count <= k){
        int t;
        cin >> t;
        wait.push({count, t});
        count++;
    }
    //处理过程
    int curTime = 0;
    count = 1;
    vector<int> time (k+1);
    while (count<=k){
        //找出当前队列最短时间
        int minT = INT_MAX;
        for (int i=0; i<n; i++) {
            if (!window[i].empty()){
                int t = window[i].front().t;
                if (t < minT){
                    minT = t;
                }
            }
        }
        //若已经到了17:00，把当前窗口正在进行的服务完就结束
        if (curTime+minT >= 540){ 
            for (int i=0; i<n; i++){
                if (!window[i].empty()){
                    time[window[i].front().id] = curTime + window[i].front().t;
                }
            }
            break;
        }
        //更新当前时间
        curTime += minT;
        //修改所有队列时间
        for (int i=0; i<n; i++){
            if (!window[i].empty()){
                window[i].front().t -= minT;
                if (window[i].front().t==0){
                    //记录完成时间，出队
                    time[window[i].front().id] = curTime;
                    window[i].pop();
                    //等待区域入队
                    if (!wait.empty()) {
                        window[i].push(wait.front());
                        wait.pop();
                    }
                    count++;
                }
            }
        }
    }
    for (int i=0; i<q; i++){
        int id;
        cin >> id;
        int t = time[id];
        if (t==0){
            printf("Sorry\n");
        }
        else {
            printf("%02d:%02d\n", 8+t/60, t%60);
        }
    }
    return 0;
}


