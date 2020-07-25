#include <iostream> 
#include <vector> 
#include <unordered_map> 
#include <algorithm> 
using namespace std; 

struct Info{
    string id;
    int time;
    string state;
};

bool cmp(Info &i1, Info &i2){
    return i1.time < i2.time;
}

int main() { 
    int n, k;
    scanf("%d %d", &n, &k);
    vector<Info> infos(n);
    for (int i=0; i<n; i++){
        char id[8], state[4];
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s", id, &hh, &mm, &ss, state);
        infos[i].id = id;
        infos[i].time = hh * 3600 + mm * 60 + ss;
        infos[i].state = state;
    }

    sort(infos.begin(), infos.end(), cmp);

    vector<Info> newInfos;  //筛选有效信息
    int maxTime = 0; //记录最长停车时间
    vector<string> plates;  //记录最长停车时间对应车牌
    unordered_map<string, int> mmap;  //记录每个车牌停车总时间
    for (int i=0; i<n; i++){
        if (infos[i].state == "in"){
            for (int j=i+1; j<n; j++){
                if (infos[j].id==infos[i].id){
                    if (infos[j].state == "out"){
                        newInfos.push_back(infos[i]);
                        newInfos.push_back(infos[j]);
                        infos[j].state = "";  //删除信息，避免重复匹配
                        mmap[infos[i].id] += infos[j].time - infos[i].time;
                        if (mmap[infos[i].id] > maxTime){
                            maxTime = mmap[infos[i].id];
                            plates.clear();
                            plates.push_back(infos[i].id);
                        }
                        else if (mmap[infos[i].id] == maxTime){
                            plates.push_back(infos[i].id);
                        }
                    }
                    break;
                }
            }
        }
    }

    sort(newInfos.begin(), newInfos.end(), cmp);
    int num = 0;  //查询信息升序，可利用上一次的数量，最终存储到num中
    int j = 0;  //当前检查信息下标
    for (int i=0; i<k; i++){
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 3600 + mm * 60 + ss; 
        while (j<newInfos.size() && newInfos[j].time<=time){
            if (newInfos[j].state == "in") num++;
            else num--;
            j++;
        }
        printf("%d\n", num);
    }

    sort(plates.begin(), plates.end());
    for (int i=0; i<plates.size(); i++){
        printf("%s ", plates[i].c_str());
    }
    int hh = maxTime / 3600;
    int mm = maxTime % 3600 / 60;
    int ss = maxTime % 60;
    printf("%02d:%02d:%02d\n", hh, mm, ss);
    return 0;
}
