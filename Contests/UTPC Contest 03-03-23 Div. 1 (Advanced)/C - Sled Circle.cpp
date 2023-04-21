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
    if(n == 1){
        cout << 0 << " " << 0 << '\n';
        return 0;
    }
    vector<int> jumps(n);
    for(int i = 0; i < n; i++){
        cin >> jumps[i];
    }
 
    vector<int> pos(n);
    for(int i = 0; i < n; i++) pos[i] = i;
    for(int i = 0; i < 1001; i++){
        for(int j = 0; j < n; j++){
            pos[j] = (pos[j] + jumps[j]) % n;
 
        }
        set<int> conj;
        for(int j = 0; j < n; j++){
            conj.insert(pos[j]);
        }
        if(conj.size() == 1){
            cout << i + 1 << " " << *conj.begin() << '\n';
            return 0;
        }
 
    }
    cout << -1 << '\n';
    return 0;
}