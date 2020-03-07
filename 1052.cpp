#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int addr;
    int data;
    int next;
};
bool cmp(Node &n1, Node &n2){
    return n1.data < n2.data;
}
int main(){
    int n, head;
    cin >> n >> head;
    vector<Node> mmap(100000);
    while (n--){
        Node node;
        cin >> node.addr >> node.data >> node.next;
        mmap[node.addr] = node;
    }
    vector<Node> nodes;
    while(head!=-1){
        nodes.push_back(mmap[head]);
        head = mmap[head].next;
    }
    sort(nodes.begin(), nodes.end(), cmp);
    printf("%d ", (int)nodes.size());
    for (int i=0; i<nodes.size(); i++){
        printf("%05d\n%05d %d ", nodes[i].addr, nodes[i].addr, nodes[i].data);
    }
    printf("-1\n");
    return 0;
}
