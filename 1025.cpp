#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu{
    string id;   
    int score;
    int localNum;
    int localRank;
};
bool cmp(Stu s1, Stu s2){
    return s1.score==s2.score ? s1.id < s2.id : s1.score > s2.score;
}
int main(){
    int n, k;
    cin >> n;
    vector<Stu> S;
    int pos = 0;
    for (int i=0; i<n; i++){
        cin >> k;
        for (int j=0; j<k; j++){
            Stu temp;
            cin >> temp.id >> temp.score;
            temp.localNum = i + 1;
            S.push_back(temp);
        }
        sort(S.begin()+pos, S.end(), cmp);
        S[pos].localRank = 1;
        for (int j=1; j<k; j++){
            S[pos+j].localRank = (S[pos+j].score==S[pos+j-1].score ? S[pos+j-1].localRank : j+1);
        }
        pos += k;
    }
    sort(S.begin(), S.end(), cmp);
    cout << S.size() << endl;
    cout << S[0].id << " " << 1 << " " << S[0].localNum << " " << 1 << endl;
    int preRank = 1;
    for (int i=1; i<S.size(); i++){
        int rank = i+1;
        if (S[i].score==S[i-1].score){
            rank = preRank; 
        }
        else {
            preRank = rank; 
        }
        cout << S[i].id << " " << rank << " " << S[i].localNum << " " << S[i].localRank << endl;
    }
    return 0;
}

