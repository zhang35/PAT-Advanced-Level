#include <iostream>
#include <set>
#include <stack>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    stack<int> ss;
    multiset<int> mm;  //记录所有数据
    multiset<int>::iterator midit;  //中位数指针
    char cmd[11];
    while (n--){
        scanf("%s", cmd);
        if (cmd[1] == 'u'){
            int key;
            scanf("%d", &key);
            ss.push(key);
            mm.insert(key);
            if (mm.size()==1){
                midit = mm.begin();
            }
            else{
                if (mm.size()%2 == 0){
                    if (key < *midit){
                        midit--;
                    }
                }
                else{
                    if (key >= *midit){
                        midit++;
                    }
                }
            }
        }
        else if (cmd[1] == 'o'){
            if (ss.empty()){
                printf("Invalid\n");
            }
            else{
                int key = ss.top();
                ss.pop();
                printf("%d\n", key);
                if (key == *midit){
                    multiset<int>::iterator temp = midit;
                    if (mm.size()%2 == 0){
                        midit++;
                    }
                    else{
                        midit--;
                    }
                    mm.erase(temp);
                }
                else{
                    if (mm.size()%2 == 0){
                        if (key < *midit){
                            midit++;
                        }
                    }
                    else{
                        if (key > *midit){
                            midit--;
                        }
                    }
                    mm.erase(mm.find(key));
                }
            }
        }
        else {
            if (ss.empty()){
                printf("Invalid\n");
            }
            else{
                printf("%d\n", *midit);
            }
        }
    }
    return 0;
}
