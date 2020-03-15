#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person{
    int id;
    int v;
    int t;
    int level;
};
bool cmp(Person &p1, Person &p2){
    if (p1.level == p2.level){
        if (p1.v + p1.t == p2.v + p2.t){
            if (p1.v == p2.v) {
                return p1.id < p2.id;
            }
            return p1.v > p2.v;
        }
        return (p1.v + p1.t > p2.v + p2.t);
    }
    return p1.level < p2.level;
}
int main(){
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    vector<Person> P;
    for (int i=0; i<n; i++){
        int id, v, t;
        scanf("%d%d%d", &id, &v, &t);
        if (v>=l && t>=l){
            if (v >= h){
                if (t >= h){
                    P.push_back({id, v, t, 0});
                }
                else{
                    P.push_back({id, v, t, 1});
                }
            }
            else if(v >= t){
                P.push_back({id, v, t, 2});
            }
            else{
                P.push_back({id, v, t, 3});
            }
        }
    }
    sort(P.begin(), P.end(), cmp);
    printf("%d\n", (int)P.size());
    for (int i=0; i<P.size(); i++){
        printf("%08d %d %d\n", P[i].id, P[i].v, P[i].t);
    }
    return 0;
}

