#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 998244353;
const int ms = 1e5 + 5;
int fExp(int a, int b){
    int ans = 1;
    while(b){
        if(b&1) ans = ans * a % mod;
        a = a*a % mod;

        b >>= 1;
    }

    return ans;
}

map <int, int> primeFact(int x){
    map <int, int> ans;
    for(int i = 2; i*i <= x; i++){
        if(x%i) continue;

        while(!(x%i)){
            x /= i;
            ans[i]++;
        }
    }

    if(x) ans[x] = 1;

    return ans;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int ans = 1;
    bool flag = true;
    vector<int> TOME(ms, 0);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        if(a % b) flag = false;

        auto fA = primeFact(a);
        auto fB = primeFact(b);

        //int aux = b / gcd(a, b);
        for(auto &i : fB){
            if(i.second - fA[i.first] <= 0) continue;
            flag = false;
            TOME[i.first]= max(TOME[i.first], 1ll);
        }
    }

    for(int i=2; i<ms; i++){
        if(TOME[i] == 0) continue;
        ans = (ans*i)%mod;
    }

    cout << (flag ? 2:ans) << "\n";
}