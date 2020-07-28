#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> POW(21);  //备忘录
int maxSum = 0;
vector<int> maxPath;

void findFactor(int n, int k, int p, vector<int> &path, int index, int sum, int maxFactor){
    if (k==0){
        if (n==0 && sum > maxSum){
            maxSum = sum;
            maxPath = path;
        }
        return;
    }
    if (n < k) return;  //剪枝
    //因子取值范围，从大向小深度遍历，确保序列降序，且sum相同时前面的序列一定是最大的
    for (int i=maxFactor; i>=1; i--){
        if (POW[i]<=n){  //剪枝 
            path[index] = i;
            findFactor(n-POW[i], k-1, p, path, index+1, sum+i, i);  //限制maxFactor很关键
        }
    }
}

int main() {
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    
    int maxFactor = 0;
    for (maxFactor=1; pow(maxFactor, p) <= n; maxFactor++) 
        POW[maxFactor] = pow(maxFactor, p);
    maxFactor--;
    vector<int> path(k);
    findFactor(n, k, p, path, 0, 0, maxFactor);

    if (maxSum == 0){
        printf("Impossible\n");
    }
    else{
        printf("%d = %d^%d", n, maxPath[0], p);
        for (int i=1; i<maxPath.size(); i++){
            printf(" + %d^%d", maxPath[i], p);
        }
    } 
    return 0;
}
