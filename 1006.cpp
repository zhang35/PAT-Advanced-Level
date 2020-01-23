#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string minId = "";
    string maxId = "";
    string minTime = "23:59:59";
    string maxTime = "00:00:00";
    for (int i=0; i<n; i++){
        string id, t1, t2;
        cin >> id >> t1 >> t2;
        if (t1 < minTime){
            minTime = t1;
            minId = id;
        }
        if (t2 > maxTime){
            maxTime = t2;
            maxId = id;
        }
    }
    cout << minId << " " << maxId << endl;
    return 0;
}
