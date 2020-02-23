#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    unordered_map<string, set<int> > stu;
    for (int i=0; i<k; i++){
        int course, m;
        scanf("%d %d", &course, &m);
        for (int j=0; j<m; j++){
            char buf[5];
            scanf("%s", buf);
            string name(buf);
            stu[name].insert(course);
        }
    }
    for (int i=0; i<n; i++){
        char buf[5];
        scanf("%s", buf);
        string name(buf);
        printf("%s %d", buf, stu[name].size());
        for (auto it=stu[name].begin(); it!=stu[name].end(); ++it){
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}
