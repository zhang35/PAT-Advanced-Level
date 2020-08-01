#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int l, r;
};

int main() {
    int n;
    cin >> n;

    if (n==1){
        cout << "YES 0" << endl;
        return 0;
    }

    vector<Node> nodes(n);
    vector<bool> isChild(n);
    for (int i=0; i<n; i++){
        string l, r;
        cin >> l >> r;
        if (l!="-") {
            nodes[i].l = stoi(l);
            isChild[nodes[i].l] = true;
        }
        else{
            nodes[i].l = -1;
        }
        if (r!="-") {
            nodes[i].r = stoi(r);
            isChild[nodes[i].r] = true;
        }
        else{
            nodes[i].r = -1;
        }
    }

    int root = 0;
    while (isChild[root]) root++;

    bool flag = true;
    queue<int> que;
    que.push(root);
    for (int pNum=n/2; pNum>1; pNum--){
        int p = que.front();
        if (nodes[p].l==-1 || nodes[p].r==-1) {
            flag = false;
            break;
        }
        que.pop();
        que.push(nodes[p].l);
        que.push(nodes[p].r);
    }
    int lastP = que.front();
    if (nodes[lastP].l == -1) flag = false;
    if (flag){
        root = nodes[lastP ].r==-1 ? nodes[lastP].l : nodes[lastP].r; 
        cout << "YES " << root;
    }
    else{
        cout << "NO " << root;
    }
    return 0;
}
