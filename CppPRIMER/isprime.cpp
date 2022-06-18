#include<bits/stdc++.h>

using namespace std;


int prime[10]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    int s = 0, t = n - 1;
    while (!(t % 2)) ++s, t >>= 1; // 求解 n-1=2^s*t
    for (int i = 0; i < 10 && prime[i] < n; ++i) {
        int a = prime[i];
        int b = 1, m = a, p = t;
        while (p) { //快速幂，求 b=a^t
            if (p % 2) b = ((long long) b * m) % n;
            m = ((long long)m * m) % n;
            p >>= 1;
        }
        if (b == 1) continue;
        for (int j = 1; j <= s; ++j) { // 进行 s 次二次检验
            int k = ((long long)b * b) % n;
            if(k == 1 && b != n-1) return false;
            b = k;
        }
        if (b != 1) return false;
    }
    return true;
}

int main(){
    for(int i = 151; i < 190;i++){
        if(isPrime(i)){
            cout<<i<<endl;

        }
    }
    return 0;
}