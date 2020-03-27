#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node{
    int addr;
    int data;
    int next;
};
int main(){
    int head, n, k;
    scanf("%d %d %d", &head, &n, &k);
    unordered_map<int, Node> M;
    for (int i=0; i<n; i++){
        Node temp;
        scanf("%d %d %d", &temp.addr, &temp.data, &temp.next);
        M[temp.addr] = temp;
    }
    //过滤掉不在链表中的节点
    vector<Node> L;
    for (int h=head; h!=-1; h=M[h].next) {
        L.push_back(M[h]);
    }
    n = L.size(); 
    //逆序打印每组节点
    int i = 0;
    while (i+k <= n){
        for (int j=i+k-1; j>=i; j--){
            if (j==k-1){
                printf("%05d %d", L[j].addr, L[j].data);
            }
            else{
                printf(" %05d\n%05d %d", L[j].addr, L[j].addr, L[j].data);
            }
        }
        i += k;
    }
    //打印剩下的
    while (i < n){
        printf(" %05d\n%05d %d", L[i].addr, L[i].addr, L[i].data);
        i++;
    }
    printf(" -1\n");
    return 0;
}
