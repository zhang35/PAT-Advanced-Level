#include <iostream>
using namespace std;

long gcd(long a, long b){
    while (b!=0){
        long r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int n;
    long a1, b1;
    scanf("%d %ld/%ld", &n, &a1, &b1);
    for (int i=1; i<n; i++){
        long a2, b2;
        scanf("%ld/%ld", &a2, &b2);
        long g = gcd(b1, b2);  //最大公约数
        a1 = b2 / g * a1 + b1 / g * a2;
        b1 = b1 / g * b2;
    }
    if (a1 < 0){
        a1 = -a1;
        printf("-");
    }
    if (a1 == 0){
        printf("0");
    }
    long i = a1 / b1;  //取整数部分
    a1 %= b1;  //去掉整数后的小数部分
    if (i != 0){
        printf("%ld", i);
    }
    if (a1 != 0){
        if (i != 0){
            printf(" ");
        }
        long g = gcd(a1, b1);
        printf("%ld/%ld", a1/g, b1/g);
    }
    return 0;
}
