#include <iostream>
using namespace std;

int main(){
    const string word[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string s;
    cin >> s;
    int sum = 0;
    for (int i=0; i<s.size(); i++){
        sum += (s[i] - 48);
    }
    s = to_string(sum);
    cout << word[s[0]-48];
    for (int i=1; i<s.size(); i++){
        cout << " " << word[s[i]-48];
    }
    cout << endl;
    return 0;
}
