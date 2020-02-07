#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct book{
    string id;
    string title;
    string author;
    set<string> keywords;
    string publisher;
    string year;
};
bool cmp(book &b1, book &b2){
    return b1.id < b2.id; 
}
int main(){
    int n;
    cin >> n;
    getchar();
    vector<book> B(n);
    for (int i=0; i<n; i++){
        getline(cin, B[i].id);
        getline(cin, B[i].title);
        getline(cin, B[i].author);

        string keywords;
        getline(cin, keywords);
        stringstream ss(keywords);
        string temp;
        while (ss >> temp){
            B[i].keywords.insert(temp);
        }

        getline(cin, B[i].publisher);
        getline(cin, B[i].year);
    }

    sort(B.begin(), B.end(), cmp);

    int m;
    cin >> m;
    for (int i=0; i<m; i++){
        int cmd;
        cin >> cmd; 
        getchar();
        getchar();
        string para;
        getline(cin, para);
        cout << cmd << ": " << para << endl;

        bool found = false;
        if (cmd==1){
            for (int j=0; j<n; j++){
                if (B[j].title==para){
                    cout << B[j].id << endl;
                    found = true;
                }
            }
        }
        else if(cmd==2){
            for (int j=0; j<n; j++){
                if (B[j].author==para){
                    cout << B[j].id << endl;
                    found = true;
                }
            }
        }
        else if(cmd==3){
            for (int j=0; j<n; j++){
                if (B[j].keywords.find(para)!=B[j].keywords.end()){
                    cout << B[j].id << endl;
                    found = true;
                }
            }
        }
        else if(cmd==4){
            for (int j=0; j<n; j++){
                if (B[j].publisher==para){
                    cout << B[j].id << endl;
                    found = true;
                }
            }

        }
        else if(cmd==5){
            for (int j=0; j<n; j++){
                if (B[j].year==para){
                    cout << B[j].id << endl;
                    found = true;
                }
            }
        }
        if (!found){
            cout << "Not Found" << endl;
        }
    }
    return 0;
}
