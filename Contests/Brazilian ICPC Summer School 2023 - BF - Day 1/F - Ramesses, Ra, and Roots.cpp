#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int gcd_dif(int n){
    int g = 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            int exp = 0;
            while(n % i == 0){
                n /= i;
                exp++;
            }
            g = gcd(g, exp);
        }
    }
    if(n > 1) g = gcd(g, 1);
    return g;
}

map<int,int> answ;
void getDiv(int n){
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            answ[i]++;
            if(n / i != i) answ[n / i]++;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    
    vector<int> v(n);
    int cnt_one = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] == 1) cnt_one++;
        int g = gcd_dif(v[i]);
        getDiv(g);
    }
    for(int i = 0; i < q; i++){
        int query;
        cin >> query;
        cout << answ[query] + cnt_one << '\n';
    }
    return 0;
}