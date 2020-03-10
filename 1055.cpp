#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Person{
    string name;
    int age;
    int worth;
};

bool cmp(Person &p1, Person &p2){
    if (p1.worth==p2.worth){
        if(p1.age==p2.age){
            return p1.name < p2.name;
        }
        return p1.age < p2.age;
    }
    return p1.worth > p2.worth;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<Person> p(n);
    for (int i=0; i<n; i++){
        cin >> p[i].name >> p[i].age >> p[i].worth;
    }
    sort(p.begin(), p.end(), cmp);
    for (int i=0; i<k; i++){
        int m, l, h;
        cin >> m >> l >> h;
        cout << "Case #" << i+1 << ":" << endl;
        int count = m;
        for (int j=0; j<n && count>0; j++) {
            if (p[j].age>=l && p[j].age<=h){
                cout << p[j].name << " " << p[j].age << " " << p[j].worth << endl;
                count--;
            }
        }
        if (count==m){
            cout << "None" << endl;
        }
    }
    return 0;
}
