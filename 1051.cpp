#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> a(n); 
    for (int i=0; i<k; i++){ 
        for (int j=0; j<n; j++){ 
            cin >> a[j];
        }
        bool ret = true;
        //l到r是降序序列
        int l = 0;
        while (l<n){
	        //找比a[l]小的元素构成的序列
            int r = l+1;
            while (r<n && a[r]<a[l]){
            	//若非递减，则不合法
                if (a[r]>a[r-1]){
                    ret = false;
                    break;
                }
                r++;
            }
            //若长度大于栈高，则不合法
            if (r-l > m){
                ret = false;
                break;
            }
            l = r;
        }
        if (ret){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
