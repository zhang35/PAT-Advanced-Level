#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dist(n+1);
    int sum = 0;  //周长
    for(int i = 1; i <= n; i++){
        int d;
        cin >> d;
        sum += d;
        dist[i] = sum;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        if (s > t){
            swap(s, t);
        }
        int len = dist[t-1] - dist[s-1];
        cout << min(len, sum - len) << endl;
    }
    return 0;
}

