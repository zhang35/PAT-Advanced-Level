#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    if (n>0){
        if (n==1){
            cout << 1;
        }
        else {
            unordered_map<int, vector<int> > mmap; //建立非叶节点号及孩子数组映射
            for (int i=0; i<m; i++){
                int p, k;
                cin >> p >> k;
                vector<int> nodes(k);
                for (int j=0; j<k; j++){
                    cin >> nodes[j];
                }
                mmap[p] = nodes;
            }
            vector<int> v;
            v.push_back(1);
            cout << "0";
            while (v.size()>0){
                int count = 0;
                vector<int> newV;
                for (int i=0; i<v.size(); i++){
                    for (int j=0; j<mmap[v[i]].size(); j++){
                        if (mmap.find(mmap[v[i]][j])==mmap.end()) {  //未出现在非叶中，是叶子
                            count++;
                        }
                        else {
                            newV.push_back(mmap[v[i]][j]);
                        }
                    }
                }
                v = newV;
                cout << " " << count;
            }

        }
        cout << endl;
    }
    return 0;
}
