#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int hobbies[1001],father[1001],level[1001],isRoot[1001];

void init() {
    for(int i=1;i<1001;i++){
        father[i] = i;
        level[i] = 0;
    }
}

int findFather(int x) {
    return x == father[x] ? x : (father[x] = findFather(father[x]));
}

void Union(int a,int b) {
    int fa=findFather(a);
    int fb=findFather(b);
    if (level[fa] <= level[fb])
        father[fa] = fb;
    else
        father[fb] = fa;
    if(level[fa]==level[fb] && fa!=fb)
        level[fb]++;
}

int main(){
    int n;
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d:",&k);
        for(int j=0;j<k;j++){
            int t;
            scanf("%d",&t);
            if(hobbies[t]==0)
                hobbies[t]=i;//记录这是谁的爱好
            Union(i,hobbies[t]);
        }
    }
    for(int i=1;i<=n;i++){
        isRoot[findFather(i)]++;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(isRoot[i]!=0)
            cnt++;
    }
    printf("%d\n",cnt);
    sort(isRoot,isRoot+n+1,greater<int>());
    printf("%d",isRoot[0]);
    for(int i=1;i<cnt;i++){
        printf(" %d",isRoot[i]);
    }
    return 0;
}
