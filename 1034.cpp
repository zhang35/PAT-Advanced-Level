#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Head{
    string name;
    int num;
};
bool cmp(Head h1, Head h2){
    return h1.name < h2.name;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n, k;
    cin >> n >> k;
    vector<unordered_map<string, int> > m;
    for (int i=0; i<n; i++){
        string a, b;
        int t;
        cin >> a >> b >> t;
        bool found = false;
        for (int j=0; j<m.size(); j++) {
            if (m[j].find(a)!=m[j].end() || m[j].find(b)!=m[j].end()){
                //若两个帮派交叉则合并二者
                for (int k=j+1; k<m.size(); k++) {
                    if (m[k].find(a)!=m[k].end() || m[k].find(b)!=m[k].end()){
                        for (auto it=m[k].begin(); it!=m[k].end(); ++it){
                            m[j][it->first] += it->second;
                        }
                        m[k].clear();
                        break;
                    }
                }
                m[j][a] += t;
                m[j][b] += t;
                found = true;
                break;
            }
        }
        if (!found){
            unordered_map<string, int> tempMap;
            tempMap[a] = t;
            tempMap[b] = t;
            m.push_back(tempMap);
        }
    }

    vector<Head> h;
    for (int i=0; i<m.size(); i++){
        if (m[i].size() > 2){
            int total = 0;
            int maxT = 0; 
            string head = "";
            for (auto it=m[i].begin(); it!=m[i].end(); ++it){
                total += it->second;
                if (it->second > maxT){
                    maxT = it->second;
                    head = it->first;
                }
            }
            if (total/2 > k){  //每对通话时间统计了2次
                h.push_back({head, (int)m[i].size()});
            }
        }
    } 
    sort(h.begin(), h.end(), cmp);
    cout << h.size() << endl;
    for (int i=0; i<h.size(); i++){
        cout << h[i].name << " " << h[i].num << endl;
    } 
    return 0;
}
