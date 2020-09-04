#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> fa(10001), M(10001), A(10001);

struct Property {
    int id;
    int num;
    double M;
    double A;
};

bool cmp(Property p1, Property p2) {
    return p1.A == p2.A ? p1.id<p2.id : p1.A>p2.A;
}

void init() {
    for (int i = 1; i < fa.size(); i++) {
        fa[i] = i;
    }
}

int find(int x) {
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx < fy) {
        fa[fy] = fx;
    }
    else {
        fa[fx] = fy;
    }
}

int main()
{
    init();
    set<int> ids;  //记录所有出现过的id
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id;
        vector<int> family;
        for (int j = 0; j < 3; j++) {
            cin >> id;
            if (id >= 0) {
                family.push_back(id);
                ids.insert(id);
            }
        }

        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> id;
            family.push_back(id);
            ids.insert(id);
        }

        for (int j = 1; j < family.size(); j++) {
            Union(family[0], family[j]);
        }

        cin >> M[family[0]] >> A[family[0]];
    }

    vector<int> fathers;
    vector<Property> pros(10001);
    for (auto id : ids) {
        int father = find(id);
        if (father == id) {
            fathers.push_back(id);
            pros[id].id = id;
        }

        pros[father].num++;
        pros[father].M += M[id];
        pros[father].A += A[id];
    }

    cout << fathers.size() << endl;

    vector<Property> fatherPros(fathers.size());
    for (int i = 0; i < fathers.size(); i++) {
        fatherPros[i] = pros[fathers[i]];
        fatherPros[i].M = fatherPros[i].M / fatherPros[i].num;
        fatherPros[i].A = fatherPros[i].A / fatherPros[i].num;
    }

    sort(fatherPros.begin(), fatherPros.end(), cmp);
    for (int i = 0; i < fatherPros.size(); i++) {
        printf("%04d %d %.3f %.3f\n", fatherPros[i].id, fatherPros[i].num, fatherPros[i].M, fatherPros[i].A);
    }

    return 0;
}