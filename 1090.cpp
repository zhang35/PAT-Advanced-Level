#include <iostream> 
#include <vector> 
#include <cmath> 
using namespace std; 

int maxDepth = 0;
int num = 0;

void dfs(vector<vector<int> > &e, int cur, int depth){
    if (e[cur].size()==0){
        if (depth > maxDepth){
            maxDepth = depth;
            num = 1;
        }
        else if (depth == maxDepth){
            num++;
        }
        return;
    }
    depth++;    
    for (int i=0; i<e[cur].size(); i++){
        dfs(e, e[cur][i], depth);
    }
}

int main() { 
    int n;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    vector<vector<int> > e(n+1);  //邻接表,最后一个存储root
    for (int i=0; i<n; i++){
        int src;
        scanf("%d", &src);
        if (src==-1){
            e[n].push_back(i);
        }
        else{
            e[src].push_back(i);
        }
    }
    dfs(e, n, 0);
    printf("%.2f %d\n", pow((1+r/100.0), maxDepth-1) * p, num);
    return 0;
} 
