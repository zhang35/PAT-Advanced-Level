#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int len = n * m;
    unordered_map<int, int> mmap;
    for (int i=0; i<len; i++){
        int temp;
        scanf("%d", &temp);
        mmap[temp]++;
        if (mmap[temp] >= len/2){
            cout << temp << endl;
            break;
        }
    }
    return 0;
}
