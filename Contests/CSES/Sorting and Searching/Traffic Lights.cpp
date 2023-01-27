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
    
    int x, n;
    cin >> x >> n;

    vector<int> v;
    set<int> dots;
    dots.insert(0);
    dots.insert(x);
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
        dots.insert(aux);
    }

    int maxl = 0;
    int last = 0;
    for(auto i : dots){
        maxl = max(maxl, i - last);
        last = i;
    }

    vector<int> answ;
    answ.push_back(maxl);
    for(int i = n - 1; i >= 0; i--){
        auto itr = dots.lower_bound(v[i]);
        maxl = max(maxl, *(next(itr)) - *(prev(itr)));
        answ.push_back(maxl);
        
        dots.erase(itr);
        // cout << "set = " << '\n';
        // for(auto j : dots){
        //     cout << j << " ";
        // }
        // cout << '\n';
    }

    reverse(answ.begin(), answ.end());
    for(int i = 1; i < answ.size(); i++){
        cout << answ[i] << " ";
    }
    cout << '\n';
    return 0;
}