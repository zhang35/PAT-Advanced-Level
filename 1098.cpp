#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sift(vector<int> &b, int i, int n){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l >= n) return;  //到达叶子
    int maxI = i;  //记录i、l、r中最大值位置
    if (l<n && b[l]>b[maxI]) maxI = l;
    if (r<n && b[r]>b[maxI]) maxI = r;
    if (maxI != i) {
        swap(b[i], b[maxI]);
        sift(b, maxI, n);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    for (int i=0; i<n; i++){
        cin >> b[i];
    }

    int k = 1;  //首个逆序位置
    while (k<n && b[k-1]<=b[k]) k++;
    //b剩下的逆序部分是否与a后面部分相同，若相同就是Insertion Sort
    if (equal(a.begin()+k, a.end(), b.begin()+k)){
        cout << "Insertion Sort" << endl;
        sort(b.begin(), b.begin()+k+1);
    } 
    else{
        cout << "Heap Sort"  << endl;
        k = n - 1;
        while (k>0 && b[k]>=b[0]) k--;  //未排序位置边界
        swap(b[0], b[k]);  //将当前最大值放到排序区
        sift(b, 0, k); 
    }
    cout << b[0];
    for (int i=1; i<n; i++){
        cout << " " << b[i];
    }
    return 0;
}
