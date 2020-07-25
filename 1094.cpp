#include <iostream> 
#include <vector> 
using namespace std; 

int main() { 
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int> > e(n+1);
    for (int i=0; i<m; i++){
        int p, k;
        scanf("%d %d", &p, &k);
        for (int j=0; j<k; j++){
            int c;
            scanf("%d", &c);
            e[p].push_back(c);
        }
    }

    //层次遍历
    vector<int> nodes;  //当前层节点
    nodes.push_back(1);
    int maxNum = 1;
    int maxLevel = 1;
    int level = 1;
    while (nodes.size() > 0){
        level++;
        vector<int> nextNodes;
        for (int i=0; i<nodes.size(); i++){
            for (int j=0; j<e[nodes[i]].size(); j++) {
                nextNodes.push_back(e[nodes[i]][j]);
            }
        }
        if (nextNodes.size() > nodes.size()){
            maxNum = nextNodes.size();
            maxLevel = level;
        }
        nodes = nextNodes;
    }
    printf("%d %d\n", maxNum, maxLevel);
    return 0;
}
