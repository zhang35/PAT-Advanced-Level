#include <iostream>
#include <vector>
using namespace std;

void getPost(vector<int> pre, int l, int r, vector<int> &post, bool isMirror){
    if (l==r){
        post.push_back(pre[l]);
    }
    else if(l < r){
        int i = l + 1; 
        int j = r;
        if (!isMirror){
            while(i<=r && pre[i]<pre[l]) i++;
            while(j>l && pre[j]>=pre[l]) j--;
        }
        else{
            while(i<=r && pre[i]>=pre[l]) i++;
            while(j>l && pre[j]<pre[l]) j--;
        }
        if (j < i){
            getPost(pre, l+1, j, post, isMirror);
            getPost(pre, i, r, post, isMirror);
            post.push_back(pre[l]);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> pre(n);
    for(int i = 0; i < n; i++){
        cin >> pre[i];
    }
    vector<int> post;
    getPost(pre, 0, n-1, post, false);
    if (post.size()<n){  //若假设是二叉搜索树不成立
        post.clear();
        getPost(pre, 0, n-1, post, true);
    }
    if(post.size()<n){  //若假设是镜像二叉搜索树仍不成立
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << post[0];
        for (int i=1; i<n; i++){
            cout << " " << post[i];
        }
    }
    return 0;
}
