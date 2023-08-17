#include <bits/stdc++.h>

using namespace std;
#define int long long

int fact_mul(int n){
    int ans = 1;

    for(int i = 2; i*i <= n; i++){
        if(n % i) continue;
        int cnt = 0;
        while(!(n%i)){
            n /= i;
            cnt++;
        }

        if(cnt&1) ans *= i;
    }

    if(n) ans*=n;
    return ans;
}

int32_t main(){
    int x;
    cin >> x;

    int a, mul;
    mul = fact_mul(x);

    a = x / mul;
    a = sqrtl(a);
    a++;

    cout << mul*a*a - x << "\n";

    return 0;
}