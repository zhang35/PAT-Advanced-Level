#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n, k;
    scanf("%d%d", &n, &k);
    //cin >> n >> k;
    vector<vector<string> > course(k+1);
    for (int i=0; i<n; i++){
        char buf[5];
        int c;
        //cin >> name >> c;
        scanf("%s%d", buf, &c);
        string name(buf);
        for (int j=0; j<c; j++){
            int id;
            scanf("%d", &id);
            //cin >> id;
            course[id].push_back(name);
        }
    }
    for (int i=1; i<k+1; i++){
        sort(course[i].begin(), course[i].end());
        printf("%d %d\n", i, (int)course[i].size());
        //cout << i << " " << course[i].size() << endl;
        for (auto it=course[i].begin(); it!=course[i].end(); ++it){
            printf("%s\n", (*it).c_str());
            //cout << *it << endl;
        }
    }
    return 0;
}

