#include <iostream>
#include <vector>
using namespace std;

int main(){
    //提高cin、cout效率，否则测试点4超时
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > edge(m); //边表，用pair记录
    for (int i=0; i<m; i++){
        cin >> edge[i].first >> edge[i].second;
    }
    for (int i=0; i<k; i++){
        int c;
        cin >> c;
        vector<int> find(n+1); //连通分支标记，取分支中最小的节点号
        for (int j=1; j<n+1; j++){
            find[j] = j;
        }
        int count = 0; //无回路的边数
        for (int j=0; j<m; j++){
            int a = edge[j].first;
            int b = edge[j].second;
            if (a!=c && b!=c){  //排除掉被围城市c
                if (find[a] != find[b]){  //不再同一个连通分支里
                    find[a] = min(find[a], find[b]);
                    find[b] = find[a];
                    count++;
                }
            }
        }
        int repair = n - 2 - count; //剩余n-1个点，无回路时全部练上共需n-2条边
        cout << repair << endl;
    }
    return 0;
}


