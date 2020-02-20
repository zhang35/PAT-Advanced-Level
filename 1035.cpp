#include <iostream>
#include <vector>
using namespace std;

struct User{
    string name;
    string pw;
    bool modified;
};
int main(){
    int n;
    cin >> n;
    vector<User> u(n);
    int count = 0;
    for (int i=0; i<n; i++){
        cin >> u[i].name >> u[i].pw;
        bool modified = false;
        for (int j=0; j<u[i].pw.size(); j++){
            if (u[i].pw[j]=='1'){
                u[i].pw[j] = '@';
                modified = true;
            }
            else if (u[i].pw[j]=='0'){
                u[i].pw[j] = '%';
                modified = true;
            }
            else if (u[i].pw[j]=='l'){
                u[i].pw[j] = 'L';
                modified = true;
            }
            else if (u[i].pw[j]=='O'){
                u[i].pw[j] = 'o';
                modified = true;
            }
        }
        if (modified){
            u[i].modified = true;
            count++;
        }
    }
    if (count==0){
        if (n==1){
            cout << "There is 1 account and no account is modified" << endl;

        }
        else{
            cout << "There are " << n << " accounts and no account is modified" << endl;
        }
    }
    else{
        cout << count << endl;
        for (int i=0; i<n; i++){
            if (u[i].modified){
                cout << u[i].name << " " << u[i].pw << endl;
            }
        }
    }
    return 0;
}
