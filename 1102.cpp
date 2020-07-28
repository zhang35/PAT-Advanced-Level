#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int l, r;
};

void printArray(vector<int> res){
    cout << res[0];
    for (int i=1; i<res.size(); i++) 
        cout << " " << res[i];
    cout << endl;
}

void levelOrder(vector<Node> &a, int root, vector<int> &res){
    queue<int> que;
    que.push(root);
    while (!que.empty()){
        int cur = que.front();
        que.pop();
        res.push_back(cur);
        if (a[cur].l != -1) que.push(a[cur].l);
        if (a[cur].r != -1) que.push(a[cur].r);
    }
}

void inOrder(vector<Node> &a, int root, vector<int> &res){
    if (a[root].l != -1) inOrder(a, a[root].l, res);
    res.push_back(root);
    if (a[root].r != -1) inOrder(a, a[root].r, res);
}

int main() {
    int n;
    cin >> n;
    vector<Node> a(n);
    vector<bool> exist(n);
    char l, r;
    for (int i=0; i<n; i++){
        cin >> r >> l;
        if (r!='-') {
            a[i].r = r - '0'; 
            exist[a[i].r] = true;
        }
        else{
            a[i].r = -1;
        }
        if (l!='-') {
            a[i].l = l - '0'; 
            exist[a[i].l] = true;
        }
        else{
            a[i].l = -1;
        }
    }

    int root = 0;
    while (exist[root]) root++;

    vector<int> res;
    levelOrder(a, root, res);
    printArray(res);

    res.clear();
    inOrder(a, root, res);
    printArray(res);

    return 0;
}

