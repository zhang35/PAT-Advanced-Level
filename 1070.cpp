#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct P{
    float num;
    float value;
    float price;
};

bool cmp(P &p1, P &p2){
    return p1.price > p2.price;
}

int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    vector<P> p(n);
    for (int i=0; i<n; i++){
        scanf("%f", &p[i].num);
    }
    for (int i=0; i<n; i++){
        scanf("%f", &p[i].value);
        p[i].price = p[i].value / p[i].num;
    }
    sort(p.begin(), p.end(), cmp);
    float sum = 0.0;
    int i = 0;
    while (i<n && d>p[i].num){
        d -= p[i].num;
        sum += p[i].value;
        i++;
    }
    if (i<n){
        sum += (d * p[i].price);
    }
    printf("%.2f\n", sum);
    return 0;
}

