#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int l, m, n;
    scanf("%d", &l);
    vector<int> a(l);
    for (int i=0; i<l; i++){
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());

    for (n=sqrt(l); n>=1; n--){
        if (l % n == 0){
            m = l / n;
            break;
        }
    }

    vector<vector<int> > b(m, vector<int>(n));
    int pos = l - 1;

    int mm = m;  //i结束位置
    int nn = n;  //j结束位置
    int i = 0;
    int j = 0;
    while (pos >= 0){
        //i、j起始位置
        int si = i;
        int sj = j;
        while (j<nn){
            b[i][j++] = a[pos--];
        }
        i++;
        j--;
        if (pos<0) break;
        while (i<mm){
            b[i++][j] = a[pos--];
        }
        if (pos<0) break;
        i--;
        j--;
        while (j>=sj){
            b[i][j--] = a[pos--];
        }
        if (pos<0) break;
        i--;
        j++;
        while (i>si){
            b[i--][j] = a[pos--];
        }
        i++;
        j++;
        mm--;
        nn--;
    }

    for (i=0; i<m; i++){
        printf("%d", b[i][0]);
        for (j=1; j<n; j++){
            printf(" %d", b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
