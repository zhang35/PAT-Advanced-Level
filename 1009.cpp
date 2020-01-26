#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

int main(){
    map<int, double> mmap;

    int k1, k2;
    cin >> k1;
    vector<int> exp(k1);
    vector<double> coef(k1);
    for (int i=0; i<k1; i++){
        cin >> exp[i] >> coef[i];
    }

    cin >> k2;
    for (int i=0; i<k2; i++){
        int tempExp;
        double tempCoef;
        cin >> tempExp >> tempCoef;
        for (int j=0; j<k1; j++){
            int newExp = tempExp + exp[j];
            mmap[newExp] += (tempCoef * coef[j]);
            if (mmap[newExp]==0){
                mmap.erase(newExp);
            }
        }
    }

    cout << mmap.size();
    for (auto it=mmap.rbegin(); it!=mmap.rend(); ++it){
        cout << " " << it->first << " " << setprecision(1) << fixed << it->second;
    }
    cout << endl;
    return 0;
}
