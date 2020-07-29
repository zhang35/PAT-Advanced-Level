#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long sum = 0;
    for (int i=0; i<n; i++){
        double temp;
        scanf("%lf", &temp);
        sum += (long long)(temp * 1000) * (n-i) * (i+1);
    }
    printf("%.2f", sum / 1000.0);
    return 0;
}
