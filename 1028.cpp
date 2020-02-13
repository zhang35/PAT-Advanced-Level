#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu{
    string id;
    string name;
    int grade;
};
bool cmp1(Stu s1, Stu s2){
    return s1.id < s2.id;
}
bool cmp2(Stu s1, Stu s2){
    return s1.name==s2.name ? s1.id<s2.id : s1.name<s2.name;
}
bool cmp3(Stu s1, Stu s2){
    return s1.grade==s2.grade ? s1.id<s2.id : s1.grade<s2.grade;
}
int main(){
    int n, col;
    cin >> n >> col;
    vector<Stu> S(n);
    for (int i=0; i<n; i++){
        cin >> S[i].id >> S[i].name >> S[i].grade; 
    }

    if (col==1) {
        sort(S.begin(), S.end(), cmp1);
    }
    else if (col==2) {
        sort(S.begin(), S.end(), cmp2);
    }
    else if (col==3) {
        sort(S.begin(), S.end(), cmp3);
    }

    for (int i=0; i<n; i++){
        cout << S[i].id << " " << S[i].name << " " << S[i].grade << endl;
    }
    return 0;
}

