#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    char results[] = {'W', 'T', 'L'};
    float profit = 1.0;
    for (int i=0; i<3; i++){
        float best = 0.0;
        int bet = -1;
        for (int j=0; j<3; j++){
            float temp;
            cin >> temp;
            if (temp > best){
                best = temp;
                bet = j;
            }
        }
        profit *= best;
        cout << results[bet] << " ";
    }
    profit = (profit * 0.65 - 1) * 2;
    cout << setprecision(2) << fixed << profit << endl;
    return 0;
}
