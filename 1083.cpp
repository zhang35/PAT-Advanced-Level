#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu{
    string name;
    string id;
    int grade;
};
bool cmp(Stu s1, Stu s2){
    return s1.grade > s2.grade;
}
int main(){
    int n;
    cin >> n;
    vector<Stu> S(n);
    for (int i=0; i<n; i++){
        cin >> S[i].name >> S[i].id >> S[i].grade;
    }
    int l, h;
    cin >> l >> h;
    vector<Stu> R;
    for (int i=0; i<n; i++){
        if (S[i].grade>=l && S[i].grade<=h){
            R.push_back(S[i]);
        }
    }
    if (R.size()==0){
        cout << "NONE" << endl;
    }
    else{
        sort(R.begin(), R.end(), cmp);
        for (int i=0; i<R.size(); i++){
            cout << R[i].name << " "  << R[i].id << endl;
        }
    }
    return 0;
}
