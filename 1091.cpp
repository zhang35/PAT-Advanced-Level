#include <iostream> 
#include <vector> 
#include <queue> 
using namespace std; 

int m, n, l, t;
int total = 0 ;

struct Pos{
    int i, j, k;
};

int bfs(vector<vector<vector<int> > > &e, int i, int j, int k){
    int num = 1;
    queue<Pos> que;
    que.push({i, j, k});
    e[i][j][k] = 0;  //表示已访问过
    while(!que.empty()){
        Pos p = que.front();
        que.pop();
        int i = p.i;
        int j = p.j;
        int k = p.k;
        if (i>0 && e[i-1][j][k]==1){
            que.push({i-1, j, k});
            e[i-1][j][k] = 0;
            num++;
        }
        if (i<l-1 && e[i+1][j][k]==1){
            que.push({i+1, j, k});
            e[i+1][j][k] = 0;
            num++;
        }
        if (j>0 && e[i][j-1][k]==1){
            que.push({i, j-1, k});
            e[i][j-1][k] = 0;
            num++;
        }
        if (j<m-1 && e[i][j+1][k]==1){
            que.push({i, j+1, k});
            e[i][j+1][k] = 0;
            num++;
        }
        if (k>0 && e[i][j][k-1]==1){
            que.push({i, j, k-1});
            e[i][j][k-1] = 0;
            num++;
        }
        if (k<n-1 && e[i][j][k+1]==1){
            que.push({i, j, k+1});
            e[i][j][k+1] = 0;
            num++;
        }
    }
    return num;
}

int main() { 
    scanf("%d %d %d %d", &m, &n, &l, &t);
    vector<vector<vector<int> > > e(l, vector<vector<int> >(m, vector<int>(n)));
    for (int i=0; i<l; i++){
        for (int j=0; j<m; j++){
            for (int k=0; k<n; k++){
                scanf("%d", &e[i][j][k]);
            }
        }
    }
    
    for (int i=0; i<l; i++){
        for (int j=0; j<m; j++){
            for (int k=0; k<n; k++){
                if (e[i][j][k]==1){
                    int num = bfs(e, i, j, k);
                    if (num >= t){
                        total += num;
                    }
                }
            }
        }
    }

    printf("%d\n", total);
    return 0;
}
