#include <iostream> 
#include <vector> 
using namespace std; 

int main() { 
    string s1, s2;
    cin >> s1 >> s2;

    vector<int> m(128);
    for (int i=0; i<s1.size(); i++){
        m[s1[i]]++;
    }

    int dif = 0;
    for (int i=0; i<s2.size(); i++){
        if (m[s2[i]]==0) {
            dif++;
        }
        else{
            m[s2[i]]--;
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
