#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int l, r, v;
};

void inorder(vector<Node> &nodes, int root, vector<int> &a, int &k){
    if (root==-1) return;
    inorder(nodes, nodes[root].l, a, k);
    nodes[root].v = a[k++];
    inorder(nodes, nodes[root].r, a, k);
}

int main(){
    int n;
    scanf("%d", &n);

    vector<Node> nodes(n);
    for (int i=0; i<n; i++){
        scanf("%d %d", &nodes[i].l, &nodes[i].r);
    }

    vector<int> a(n);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    
    int k = 0;
    inorder(nodes, 0, a, k);

    queue<int> que;
    que.push(0);
    while (!que.empty()){
        int cur = que.front();
        que.pop();
        if (cur!=0) printf(" ");
        printf("%d", nodes[cur].v);
        if (nodes[cur].l!=-1) que.push(nodes[cur].l);
        if (nodes[cur].r!=-1) que.push(nodes[cur].r);
    }

    return 0;
}
