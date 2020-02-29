#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }

    int minExcess = INT_MAX;  //超出M的最小值
    vector<pair<int, int> > solution;  //可行解
    int i = 0;
    int j = 0;
    int sum = d[0];
    while (i<n && j<n){
        if (sum >= m){
            if (sum - m <= minExcess){
                if (sum - m < minExcess){
                    solution.clear();
                    minExcess = sum - m;
                }
                solution.push_back({i+1, j+1});
            }
            sum -= d[i];
            i++;
        }
        else{
            j++;
            if (j>=n){
                break; 
            }
            sum += d[j];
        }
    }
    for (i=0; i<solution.size(); i++){
        cout << solution[i].first << '-' << solution[i].second << endl;
    }
    return 0;
}

