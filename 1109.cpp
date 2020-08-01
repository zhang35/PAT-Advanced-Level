#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu{
    string name;
    int h;
};

bool cmp(Stu &s1, Stu &s2){
    return s1.h==s2.h ? s1.name<s2.name : s1.h > s2.h;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Stu> a(n);
    for (int i=0; i<n; i++){
        cin >> a[i].name >> a[i].h;
    }
    sort(a.begin(), a.end(), cmp);

    int index = 0;
    int m = n - n / k * (k - 1);
    for (int i=0; i<k; i++){
        vector<int> b(m);
        int pos = m / 2; 
        int delta = 0;
        for (int j=0; j<m; j++){
            b[pos+delta] = index++;
            delta = -delta;
            if (delta <= 0){
                delta -= 1;
            }
        }
        cout << a[b[0]].name;
        for (int i=1; i<m; i++){
            cout << " " << a[b[i]].name;
        }
        cout << endl;
        m = n / k;
    }
    return 0;
}
