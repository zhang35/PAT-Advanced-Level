#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr(100000);
    int h1, h2, n;
    scanf("%d %d %d", &h1, &h2, &n);
    for (int i=0; i<n; i++){
        int addr, next;
        char ch;
        scanf("%d %c %d", &addr, &ch, &next);
        arr[addr] = next;
    }

    vector<int> num(100000);
    for (int p=arr[h2]; p!=-1; p=arr[p]){
        num[p]++;
    }
    for (int p=arr[h1]; p!=-1; p=arr[p]){
        if (num[p] > 0){
            printf("%05d\n", p);
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
