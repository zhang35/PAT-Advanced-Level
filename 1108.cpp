#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    int legal = 0;
    string str;
    double temp;
    for (int i=0; i<n; i++){
        bool flag = false;
        cin >> str; 
        stringstream ss(str);
        if (ss>>temp && temp>=-1000 && temp<=1000){ 
            flag = true;
            if (str.find('.')!=string::npos && str.size()-str.find('.')>3){
                flag = false;    
            }
        }
        if (flag){
            legal++;
            sum += temp;
        }
        else{
            cout << "ERROR: " << str << " is not a legal number" << endl;
        }
    }
    if (legal==0){
        cout << "The average of 0 numbers is Undefined" << endl;
    }
    else if (legal==1){
        cout << "The average of 1 number is " << setprecision(2) << fixed << sum << endl;
    }
    else{
        cout << "The average of "<< legal << " numbers is " << setprecision(2) << fixed << sum / legal<< endl;
    }
    return 0;
}
