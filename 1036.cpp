#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string boyName = "Absent";
    string girlName = "Absent";
    int boyScore = 101; 
    int girlScore = -1; 
    for (int i=0; i<n; i++){
        string name, id;
        char gender;
        int grade;
        cin >> name >> gender >> id >> grade;
        if (gender=='M' && grade < boyScore){
            boyScore = grade;
            boyName = name + " " + id;
        }
        else if (gender=='F' && grade > girlScore){
            girlScore = grade;
            girlName = name + " " + id;
        }
    }
    cout << girlName << endl;
    cout << boyName << endl;
    if (girlScore==-1 || boyScore==101){
        cout << "NA" << endl;
    }
    else{
        cout << girlScore - boyScore << endl;
    }
    return 0;
}
