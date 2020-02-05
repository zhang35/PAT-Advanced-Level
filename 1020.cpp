#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int i;  //后序数列中的位置
    int l;  //前序数列中左边界
    int r;  //前序数列中右边界
};

int main(){
    int n;
    cin >> n;
    vector<int> post(n);
    vector<int> in(n);
    for (int i=0; i<n; i++){
        cin >> post[i]; 
    }
    for (int i=0; i<n; i++){
        cin >> in[i]; 
    }
    queue<Node> q;
    q.push({n-1, 0, n-1});
    cout << post[n-1];
    while (!q.empty()){
        Node root = q.front();
        q.pop();
        int v = post[root.i];
        if (root.l>=root.r){
            continue;
        }
        int rightCount = 0;
        for (int i=root.r; i>=root.l&&in[i]!=v; i--){
            rightCount++;
        }
        int leftCount = root.r - root.l - rightCount;
        if (leftCount > 0){
            int leftRoot = root.i - 1 - rightCount;
            cout << " " << post[leftRoot];
            q.push({leftRoot, root.l, root.l+leftCount-1});
        }
        if (rightCount > 0){
            int rightRoot = root.i - 1;
            cout << " " << post[rightRoot];
            q.push({rightRoot, root.r-rightCount+1, root.r});
        }
    }
    cout << endl;
    return 0;
}
