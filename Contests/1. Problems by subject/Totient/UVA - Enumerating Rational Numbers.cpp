#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    const int ms = 2*1e5 + 10;
    vector<int> phi = sievePhi(ms);
    vector<int> ps(ms + 10, 0);
    ps[1] = 2;
    for(int i = 2; i <= phi.size(); i++){
        ps[i] = ps[i - 1] + phi[i];
    }

    int k;
    while(cin >> k && k != 0){
        int denominador = lower_bound(ps.begin(), ps.end(), k) - ps.begin();
        if(k == 1 || k == 2){
            cout << ((k == 1) ? 0 : 1) << "/" << denominador << '\n';
        }
        else{
            int prime = k - ps[denominador - 1];
            int numerador = -1;
            int count = 0;
            for(int i = 1; i <= denominador; i++){
                if(__gcd(denominador, i) == 1){
                    count++;
                }
                if(count == prime){
                    numerador = i;
                    break;
                }
            }
            
            cout << numerador << "/" << denominador << '\n';
        }
    }
    
    return 0;
}