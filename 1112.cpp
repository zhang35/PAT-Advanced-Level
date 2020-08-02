#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k;
    string s;
    cin >> k >> s;

    vector<int> stucked(128, -1);
    int i = 0;
    while (i<s.size()){
        bool flag = true;
        int j = i+1;
        while (j<s.size() && s[i]==s[j]) j++;
        if ((j-i) % k != 0){
            stucked[s[i]] = 0;
        }
        else if (stucked[s[i]]==-1) {
            stucked[s[i]] = 1;
        }
        i = j;
    }

    string ret = "";
    vector<bool> visited(128);
    i = 0;
    while (i<s.size()){
        ret += s[i];
        if (stucked[s[i]]){
            i += k - 1;
            if (!visited[s[i]]){
                cout << s[i];
                visited[s[i]] = true;
            }
        }
        i++;
    }
    cout << endl << ret;
    return 0;
}
