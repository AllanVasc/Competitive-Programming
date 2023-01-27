#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

// Euler's totient function from 1 to n
vector<int> sievePhi(int n){
    vector<int> phi(n + 1);
    for(int i = 0; i <= n; i++) phi[i] = i;
    for(int i = 2; i <= n; i++){
        if(phi[i] == i){
            for(int j = i; j <= n; j += i){
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}

vector<int> sieve(int n, vector<int> &phi){
    vector<int> sumGCD(n + 1, 0);

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            int d1 = i;
            sumGCD[j] += d1 * phi[j/d1];
            }
        }
    return sumGCD;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    const int ms = 1e6 + 100;
    vector<int> phi = sievePhi(ms);
    vector<int> sumGCD = sieve(ms, phi);

    vector<int> answ(phi.size());
    answ[2] = 1;
    for(int i = 3; i < phi.size(); i++){
        answ[i] = answ[i - 1] + sumGCD[i] - i;
    }

    int n;
    while(cin >> n && n != 0){
        cout << answ[n] << '\n';
    }
    return 0;
}