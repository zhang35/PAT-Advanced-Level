#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Student{
    int id;
    int ge;
    int gi;
    vector<int> option;
};
bool cmp(Student &s1, Student &s2){
    float sum1 = (s1.ge + s1.gi) / 2.0;
    float sum2 = (s2.ge + s2.gi) / 2.0;
    return sum1==sum2 ? s1.ge>s2.ge : sum1>sum2; 
}
int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> quota(m);
    for (int i=0; i<m; i++){
        scanf("%d", &quota[i]);
    }
    vector<Student> t(n);
    for (int i=0; i<n; i++){
        t[i].id = i;
        t[i].option.resize(k);
        scanf("%d %d", &t[i].ge, &t[i].gi);
        for (int j=0; j<k; j++){
            scanf("%d", &t[i].option[j]);
        }
    }
    sort(t.begin(), t.end(), cmp);
    vector<int> rank(n);
    vector<vector<int> > admit(m);
    for (int i=0; i<n; i++){
        int id = t[i].id;
        if(i>0 && t[i].ge==t[i-1].ge && t[i].gi==t[i-1].gi){
            rank[id] = rank[t[i-1].id];
        }
        else{
            rank[id] = i;
        }
        for (int j=0; j<k; j++){
            int k = t[i].option[j];  //当前志愿
            if (quota[k] > 0){  //学校名额未满
                admit[k].push_back(t[i].id);
                quota[k]--;
                break;
            }
            //学校名额满了，看该学校最后一名是否与其排行相同
            else if (rank[id] == rank[admit[k][admit[k].size()-1]]){
                admit[k].push_back(t[i].id);
                break;
            }
        }
    }
    for (int i=0; i<m; i++){
        sort(admit[i].begin(), admit[i].end());
        for (int j=0; j<admit[i].size(); j++){
            if (j>0) {
                printf(" ");
            }
            printf("%d", admit[i][j]);
        }
        printf("\n");
    }
    return 0;
}

