#include <iostream>
using namespace std;

int main(){
    int g1, s1, k1, g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    int addition = 0;
    k1 += k2;
    if (k1 >= 29){
        k1 -= 29;
        addition = 1;
    }
    s1 += s2;
    s1 += addition;
    if (s1 >= 17){
        s1 -= 17;
        addition = 1;
    }
    else{
        addition = 0;
    }
    g1 += g2;
    g1 += addition;
    printf("%d.%d.%d\n", g1, s1, k1);
    return 0;
}
