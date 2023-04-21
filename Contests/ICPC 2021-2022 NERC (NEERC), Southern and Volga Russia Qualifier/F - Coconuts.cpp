#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

map<int,int> freq;
void add(int x){
    vector<int> factors;
    int aux = x;
    // cout << "x = " << aux << '\n';
    for(int i = 2; i * i <= x; i++){
        while(x % i == 0){
            x /= i;
            factors.push_back(i);
        }
    }
    if(x != 1) factors.push_back(x);
    map<int,int> pot;
    int maxPot = 0;
    for(int i = 0; i < factors.size(); i++){
        pot[factors[i]]++;
        if(pot[factors[i]] > maxPot) maxPot = pot[factors[i]];
    }

    for(int i = 1; i <= maxPot; i++){
        int val = 1;
        bool ok = true;
        for(auto [fact, p] : pot){
            if(p % i != 0){
                ok = false;
                break;
            }
            else{
                for(int j = 0; j < (p/i); j++) val *= fact;
            }
        }
        if(ok){
            freq[val] += aux;
            // cout << val << "^" << i << "\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int qtdOne = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 1) qtdOne++;
        else add(v[i]);
    }
    freq[1] += qtdOne;
    int answ = 0;
    for(auto x : freq){
        answ = max(answ, x.second);
    }
    cout << answ << '\n';

    return 0;
}