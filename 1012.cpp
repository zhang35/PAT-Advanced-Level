#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Info{
    int id;
    int grade;
};

bool cmp(Info i1, Info i2){
    return i1.grade > i2.grade;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<Info> > g(4, vector<Info>(n)); //四个数组分别存储a, c, m, e
    for (int i=0; i<n; i++){
        int id;
        cin >> id;
        int sum = 0;
        for (int j=1; j<4; j++){
            cin >> g[j][i].grade;
            sum += g[j][i].grade;
            g[j][i].id = id;
        }
        g[0][i].grade = sum / 3 + 0.5; //四舍五入
        g[0][i].id = id;
    }
    vector<unordered_map<int, int> > rank(4);
    for (int i=0; i<4; i++){
        sort(g[i].begin(), g[i].end(), cmp);
        int lastGrade = 101;
        int lastRank = 0;
        for (int j=0; j<n; j++){
            int id = g[i][j].id;
            if (g[i][j].grade == lastGrade){
                rank[i][id] = lastRank;
            }
            else{
                rank[i][id] = j + 1;
                lastGrade = g[i][j].grade;
                lastRank = j + 1;
            }
        }
    }
    char course[] = {'A', 'C', 'M', 'E'};
    for (int i=0; i<m; i++){
        int id; 
        cin >> id;
        if (rank[0].find(id)==rank[0].end()){
            cout << "N/A" << endl;
        }
        else {
            int best = n + 1;
            int bestCourse = -1;
            for (int j=0; j<4; j++){
                if (rank[j][id] < best){
                    best = rank[j][id];
                    bestCourse = j;
                }
            }
            cout << best << " " << course[bestCourse] << endl;
        }
    }
    return 0;
}


