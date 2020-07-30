#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int> > e;
int minDepth = 100000;
int minNum = 1;
void dfs(int cur, int depth){
    if (e[cur].size() == 0){  //到达叶子
        if (depth < minDepth){
            minNum = 1; 
            minDepth = depth;
        }
        else if(depth == minDepth){
            minNum++;
        }
        return;
    }
    for (int i=0; i<e[cur].size(); i++){
        dfs(e[cur][i], depth+1);
    }
}

int main() {
    int n;
    double p, r;
    scanf("%d %lf %lf", &n, &p, &r);
    e.resize(n);
    for (int i=0; i<n; i++){
        int m;
        scanf("%d", &m);
        e[i].resize(m);
        for (int j=0; j<m; j++){
            scanf("%d", &e[i][j]);
        }
    }

    dfs(0, 0);

    printf("%.4f %d", p * pow(1+r/100, minDepth), minNum);
    return 0;
}

