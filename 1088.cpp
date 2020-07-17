#include <iostream> 
using namespace std; 
  
int gcd(long long a, long long b){
    int r = a % b;
    while (r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

void print(long long a, long long b){
    if (a == 0){
        cout << "0";
        return;
    }

    bool flag = false;
    if (a < 0){
        cout << "(-";
        flag = true;
        a = -a;
    }
    if (a >= b){
        cout << a / b;
        a %= b;
        if (a != 0){
            cout << " ";
        }
    }
    if (a != 0){
        int r = gcd(a, b);
        cout << a/r << "/" << b/r;
    }
    if (flag){
        cout << ")";
    }
}

int main() 
{ 
    long long a1, b1, a2, b2, a3, b3;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    
    b3 = b1 * b2;
    a3 = b2 * a1 + b1 * a2;
    print(a1, b1);
    cout << " + ";
    print(a2, b2);
    cout << " = ";
    print(a3, b3);
    cout << endl;

    b3 = b1 * b2;
    a3 = b2 * a1 - b1 * a2;
    print(a1, b1);
    cout << " - ";
    print(a2, b2);
    cout << " = ";
    print(a3, b3);
    cout << endl;

    b3 = b1 * b2;
    a3 = a1 * a2;
    print(a1, b1);
    cout << " * ";
    print(a2, b2);
    cout << " = ";
    print(a3, b3);
    cout << endl;

    b3 = b1 * a2;
    a3 = b2 * a1;
    print(a1, b1);
    cout << " / ";
    print(a2, b2);
    cout << " = ";
    if (b3 < 0){
        b3 = -b3;
        a3 = -a3;
    }
    if (b3==0){
        cout << "Inf";
    }
    else{
        print(a3, b3);
    }
    cout << endl;
    return 0;
} 
