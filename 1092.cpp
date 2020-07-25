#include <iostream> 
#include <vector> 
using namespace std; 

int main() { 
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> m1(128), m2(128);
    for (int i=0; i<s1.size(); i++){
        m1[s1[i]]++;
    }
    for (int i=0; i<s2.size(); i++){
        m2[s2[i]]++;
    }

    int dif = 0;
    for (int i=0; i<128; i++){
        if (m1[i] < m2[i]){
            dif += (m2[i] - m1[i]);
        }
    }
    if (dif > 0){
        cout << "No " << dif << endl;
    }
    else{
        cout << "Yes " << s1.size()-s2.size() << endl;
    }
    return 0;
}
