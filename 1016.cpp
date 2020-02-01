#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct record{
    string name;
    string time;
    string state;
};
bool cmp(record r1, record r2){
    return (r1.name==r2.name) ? (r1.time<r2.time) : (r1.name<r2.name);
}
int main(){
    vector<int> T(24);
    int dayToll = 0;
    for (int i=0; i<24; i++){
        cin >> T[i];
        dayToll += T[i];
    }
    dayToll *= 60;
    int n;
    cin >> n;
    vector<record> R(n);
    for (int i=0; i<n; i++){
        cin >> R[i].name >> R[i].time >> R[i].state;
    }
    string month = R[0].time.substr(0, 2);
    sort(R.begin(), R.end(), cmp);
     
    int i = 0;
    string preName = "";
    float sum = 0.0;
    while (i<n){
        while (i<n && R[i].state=="off-line"){  //定位到第一个on-line
            i++;
        }
        if (i>=n-1 || R[i+1].name!=R[i].name || R[i+1].state=="on-line"){  //无配对
            i++;
            continue;
        }
        string name = R[i].name;
        if (name != preName){  //新找到一个有账单的用户
            if (sum > 0){
                cout << "Total amount: $" << setprecision(2) << fixed << sum << endl;
            }
            cout << name << " " << month << endl;
            preName = name;
            sum = 0.0;  //累计消费归0
        }
        string s[2];
        s[0] = R[i].time.substr(3, 8);  //开始时间
        s[1] = R[i+1].time.substr(3, 8);  //结束时间
        int d[2], h[2], m[2];
        for (int j=0; j<2; j++){
            stringstream ss(s[j]);
            char ch;
            ss >> d[j] >> ch >> h[j] >> ch >> m[j];
        }
        if (m[1] < m[0]){
            m[1] += 60;
            h[1]--;
        }
        if (h[1] < h[0]){
            h[1] += 24;
            d[1]--;
        }
        float cost = (d[1] - d[0]) * dayToll;  //差的整天数
        int duration = (h[1] - h[0]) * 60 + (m[1] - m[0]);  //差的分钟数
        int curToll = T[h[0]];
        for (int j=0; j<duration; j++){
            cost += curToll;
            m[0]++;
            if (m[0]==60){
                m[0] = 0;
                h[0] = (h[0] + 1) % 24;
                curToll = T[h[0]];
            }
        }
        cost /= 100;
        sum += cost;
        duration += (d[1] - d[0]) * 1440; 
        cout << s[0] << " " << s[1] << " " << duration << " $" << setprecision(2) << fixed << cost << endl;
        i += 2;
    }
    if (sum > 0){
        cout << "Total amount: $" << setprecision(2) << fixed << sum << endl;
    }
    return 0;
}
