#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n, g;
    cin >> n >> g;
    vector<int> w(n);
    unordered_map<int, int> rank;
    for (int i=0; i<n; i++){
        cin >> w[i];
    }
    vector<int> v;
    for (int i=0; i<n; i++){
        int pos;
        cin >> pos;
        v.push_back(w[pos]);
    }
    while (v.size()>1){
        int m = v.size();
        int curRank = m / g + 1;   //当前排名
        if (m % g != 0){
            curRank++;
        }
        vector<int> u;  //下一组
        int maxW = -1; 
        for (int i=0; i<m; i++){
            rank[v[i]] = curRank;
            maxW = max(maxW, v[i]);
            if ((i+1)%g==0 || i==m-1) {  //一组比较结束
                u.push_back(maxW);  //优胜者进入下一组
                maxW = -1;
            }
        }
        v = u;  //处理下一组
    }
    rank[v[0]] = 1;  //生成第一名排名
    cout << rank[w[0]];
    for (int i=1; i<n; i++){
        cout << " " << rank[w[i]];
    }
    cout << endl;
    return 0;
}
