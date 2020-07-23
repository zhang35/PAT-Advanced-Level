#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

int main() { 
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++){
        cin >> a[i]; 
    }
    for (int i=0; i<n; i++){
        cin >> b[i]; 
    }

    int i = 1; //待排序元素位置
    while (i<n && b[i]>=b[i-1]){
        i++;
    }
    if (equal(a.begin()+i, a.end(), b.begin()+i)){
        cout << "Insertion Sort" << endl;
        sort(a.begin(), a.begin()+i+1);
    }
    else {
        cout << "Merge Sort" << endl;
        bool flag = false;
        for (int k=1; k<n; k*=2){
            //归并到二者相同时，再进行一次归并后跳出
            if (a==b) flag = true;
            //l是待归并两个数组左边界
            for (int l=0; l<n-k; l+=2*k) {
                int r = min(l+2*k, n);
                sort(a.begin()+l, a.begin()+r);
            }
            if (flag) break;
        }
    }

    cout << a[0];
    for (int i=1; i<n; i++){
        cout << " " << a[i];
    }

    return 0;
} 
