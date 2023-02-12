#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    map<int, int> freq_even, freq_odd;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            freq_even[v[i]]++;
        }
        else{
            freq_odd[v[i]]++;
        }
    }
                            // freq, valor
    vector<ii> best_even(2, {-INF, -INF});
    for(auto i : freq_even){
        ii aux = {i.second, i.first};
        if(aux.first > best_even[0].first) swap(best_even[0], aux);
        if(aux.first > best_even[1].first) swap(best_even[1], aux);
    }

    vector<ii> best_odd(2, {-INF, -INF});
    for(auto i : freq_odd){
        ii aux = {i.second, i.first};
        if(aux.first > best_odd[0].first) swap(best_odd[0], aux);
        if(aux.first > best_odd[1].first) swap(best_odd[1], aux);
    }

    int answ = INF;
    if(best_even[0].second != best_odd[0].second){ // Situação otima
        answ = (n/2 - best_even[0].first) + (n/2 - best_odd[0].first);
    }
    else{
        if(best_odd[1].second != -INF) answ = min(answ, (n/2 - best_even[0].first) + (n/2 - best_odd[1].first) );
        if(best_even[1].second != -INF) answ = min(answ,(n/2 - best_even[1].first) + (n/2 - best_odd[0].first));
        if(best_even[1].second == -INF && best_odd[1].second == -INF) answ = n/2;
    }
    cout << answ << '\n';

    return 0;
}