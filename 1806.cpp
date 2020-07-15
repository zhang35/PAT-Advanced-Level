#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> pre;
vector<int> in;
vector<int> post;

//已知pre、in，求post
//root为根在pre中的下标, left、right为in中的左右边界
void Post(int root, int left, int right){
    if (left > right) return;
    //定位in数组中根的位置，存储到i中
    int i = left;
    while(i<right && in[i]!=pre[root]) i++;
    Post(root+1, left, i-1);
    Post(root+1+i-left, i+1, right);
    post.push_back(pre[root]);
}

int main(){
    int n;
    cin >> n;

    stack<int> ss;

    string cmd;
    for (int i=0; i<2*n; i++){
        int k;
        cin >> cmd;
        if (cmd=="Push"){
            cin >> k;
            ss.push(k);
            pre.push_back(k);
        }
        else{
            in.push_back(ss.top());
            ss.pop();
        }
    }

    Post(0, 0, n-1);
    
    cout << post[0];
    for (int i=1; i<n; i++){
        cout << " " << post[i];
    }
    return 0;
}
