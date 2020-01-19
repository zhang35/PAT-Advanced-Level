#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main(){
    map<int, float> coefMap;
    for (int i=0; i<2; i++){
        int k;
        cin >> k;
        for (int j=0; j<k; j++){
            int exp;
            float coef;
            cin >> exp >> coef;
            coefMap[exp] += coef;
            if (coefMap[exp]==0){
                coefMap.erase(exp);
            }
        }
    }
    cout << coefMap.size();
    for (auto it=coefMap.rbegin(); it!=coefMap.rend(); ++it){
        cout << " " << it->first << " "  << fixed << setprecision(1) << it->second;
    }
    cout << endl;
    return 0;
}
