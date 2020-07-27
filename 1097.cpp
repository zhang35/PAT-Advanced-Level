#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

struct node{
    int addr, v, next;
};

void printList(vector<node> &list){
    if (list.size()==0){
        return;
    }
    printf("%05d %d", list[0].addr, list[0].v);
    for (int i=1; i<list.size(); i++){
        printf(" %05d\n%05d %d", list[i].addr, list[i].addr, list[i].v);
    }
    printf(" -1\n");
}

int main(){
    int head, n;
    scanf("%d %d", &head, &n);
    unordered_map<int, node> mmap;
    for (int i=0; i<n; i++){
        node temp;
        scanf("%d %d %d", &temp.addr, &temp.v, &temp.next);
        mmap[temp.addr] = temp;
    }

    vector<node> list1;  //链表1
    vector<node> list2;  //链表2
    unordered_map<int, bool> exist;  //判断是否存在
    int p = head; 
    while (p != -1){
        if (!exist[abs(mmap[p].v)]){
            exist[abs(mmap[p].v)] = true;
            list1.push_back(mmap[p]);
        }
        else{
            list2.push_back(mmap[p]);
        }
        p = mmap[p].next;
    }
    
    printList(list1);
    printList(list2);
}
