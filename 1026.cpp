#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player{
    int arriveTime;
    int serveTime;
    int duration;
    int vip;
};
struct Table{
    int time;  //空闲时刻
    int sum;  //服务人数
    int vip;
};
bool cmp(Player &p1, Player &p2){
    return p1.arriveTime < p2.arriveTime;
}
bool cmp1(Player &p1, Player &p2){
    return p1.serveTime==p2.serveTime ? p1.vip>p2.vip : p1.serveTime<p2.serveTime;
}
string sec2Str(int t){
    int hh = t / 3600;
    t %= 3600;
    int mm = t / 60;
    t %= 60;
    char buffer[9];
    sprintf(buffer, "%02d:%02d:%02d", hh, mm, t);
    string s(buffer);
    return s;
}
int main(){
    int n;
    cin >> n;
    vector<Player> P;
    for (int i=0; i<n; i++){
        Player temp;
        int hh, mm, ss;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &temp.duration, &temp.vip);
        if (hh<21){  //超过21点来的，排除在外
            temp.arriveTime = hh * 3600 + mm * 60 + ss;
            if (temp.duration > 120){  //使用时间超过2小时的，按2小时算
                temp.duration = 120;
            }
            temp.duration *= 60;
            P.push_back(temp);
        }
    }
    n = P.size();
    sort(P.begin(), P.end(), cmp);

    int k, m;
    cin >> k >> m;
    vector<Table> T(k);
    for(int i=0; i<k; i++){
        T[i].time = 8 * 3600;
    }
    for(int i=0; i<m; i++){
        int index;
        cin >> index;
        T[index-1].vip = 1;
    }

    vector<bool> served(n);
    for (int count=0; count<n; count++){
        int minT = T[0].time;
        int minI = 0;
        for (int i=1; i<k; i++){
            if (T[i].time<minT){
                minT = T[i].time;
                minI = i;
            }
        }
        //下班了
        if (minT>=21 * 3600){  
            break;
        }
        //找第一个顾客
        int i = 0;
        while (i<n && served[i]){  
            i++;
        }
        //若有空闲桌子 
        if (minT <= P[i].arriveTime){
            //取第一个空闲桌子
            for (int j=0; j<k; j++){
                if (T[j].time <= P[i].arriveTime){
                    minI = j;
                    break;
                }
            }
            //若是vip，若后面有空闲vip桌，取该vip桌
            if (P[i].vip==1){
                for (int j=minI; j<k; j++){ 
                    if (T[j].time<=P[i].arriveTime && T[j].vip==1){
                        minI = j;
                        break;
                    }
                }
            }
        }
        //若无空桌子，需排队等最早结束的桌子
        else{
            //若桌子是vip桌，需检查是否有vip排队
            if (T[minI].vip==1){  
                for (int j=i; j<n&&P[j].arriveTime<=minT; j++){
                    //第一个排队的vip
                    if (P[j].vip==1 && !served[j]){
                        i = j;
                        break;
                    }
                    i++;
                }
            }
        }
        //第minI个桌子，给第i个顾客服务
        served[i] = true;
        P[i].serveTime = P[i].arriveTime<minT ? minT : P[i].arriveTime;
        T[minI].time = P[i].serveTime + P[i].duration;
        T[minI].sum++;
    }
    sort(P.begin(), P.end(), cmp1);  //按服务时间排序
    for (int i=0; i<n; i++){
        if (P[i].serveTime!=0){
            int wait = (P[i].serveTime - P[i].arriveTime + 30) / 60;  //秒数换算为分钟数，并四舍五入
            cout << sec2Str(P[i].arriveTime) << " " << sec2Str(P[i].serveTime) << " " << wait << endl;
        }
    }
    cout << T[0].sum;
    for (int i=1; i<k; i++){
        cout << " " << T[i].sum;
    }
    cout << endl;
    return 0;
}

