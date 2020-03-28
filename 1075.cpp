#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct User{
    int id;
    int total;  //总分
    int perfect;  //满分数
    vector<int> score;  //各题分数，-2:未提交过 -1:提交未通过
};
bool cmp(User &u1, User &u2){
    if (u1.total == u2.total){
        if (u1.perfect == u2.perfect){
            return u1.id < u2.id;
        }
        return u1.perfect > u2.perfect;
    }
    return u1.total > u2.total;
}
int main(){
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<int> mark(k+1);  //满分标准
    for (int i=1; i<=k; i++){
        cin >> mark[i];
    }
    unordered_map<int, User> mmap;
    for (int i=0; i<m; i++){
        int id, q, s;
        scanf("%d %d %d", &id, &q, &s);
        if (mmap.find(id)==mmap.end()){  //若该id未出现过，先初始化
            User u;
            u.id = id;
            u.total = 0;
            u.perfect = 0;
            u.score.resize(k+1);
            fill(u.score.begin(), u.score.end(), -2);  //成绩均初始化为-2
            mmap[id] = u;
        }
        if (s > mmap[id].score[q]){  //得分大于当前成绩
            mmap[id].score[q] = s;
            //重复的满分只应计1次
            if (s == mark[q]){
                mmap[id].perfect++;
            }
        }
    }
    vector<User> U;
    for (auto it=mmap.begin(); it!=mmap.end(); ++it){
        for (int i=1; i<=k; i++){
            if (it->second.score[i] >= 0){  //有一门通过的，保留该用户信息
                for (int j=i; j<=k; j++){
                    if (it->second.score[j] > 0){  //总分只计算>0的成绩
                        it->second.total += it->second.score[j];
                    }
                }
                U.push_back(it->second);
                break;
            }
        }
    }
    sort(U.begin(), U.end(), cmp);
    int rank = 1;
    for (int i=0; i<U.size(); i++){
        if (i>0 && U[i].total!=U[i-1].total){
            rank = i + 1;
        }
        printf("%d %05d %d", rank, U[i].id, U[i].total);
        for (int j=1; j<=k; j++){
            if (U[i].score[j] >= 0){  //得分非负，直接输出
                printf(" %d", U[i].score[j]);
            }
            else if (U[i].score[j] == -1){  //得分是-1，说明提交了未通过
                printf(" 0");
            }
            else{  //得分是初始值-2的情况，说明未提交过
                printf(" -");
            }
        }
        printf("\n");
    }
    return 0;
}
