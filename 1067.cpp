#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> pos(n);
    for (int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        pos[temp] = i;
    }
    int count = 0;
    int checkPos = 1;
    bool sorted = false;
    while (!sorted){
        //swap(0, i)
        while (pos[0] != 0){
            swap(pos[0], pos[pos[0]]);
            count++;
        }
        //检查是否仍存在错位
        while (checkPos<n && pos[checkPos]==checkPos){
            checkPos++;
        }
        if (checkPos==n){
            sorted = true;
        }
        else{  
            //swap(0, i)
            swap(pos[0], pos[checkPos]);
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
