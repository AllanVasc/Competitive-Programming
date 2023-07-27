#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int pos = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == n) pos = i;
        }
        vector<int> answ(n, 1);
        if(!pos){
            // tenho q aplicar em n - 1
            for(int i = 0; i < n; i++){
                if(v[i] == n - 1) pos = i;
            }
        }

        int r = pos - 1;
        int l = r;
        while(l >= 0){
            vector<int> aux;
            for(int i = r + 1; i < n; i++){
                aux.push_back(v[i]);
            }
            for(int i = r; i >= l; i--){
                aux.push_back(v[i]);
            }
            for(int i = 0; i < l; i++){
                aux.push_back(v[i]);
            }
            if(aux > answ) swap(answ, aux);
            l--;
        }
        if(pos == n - 1){
            // Aplica [l, r] em n - 1
            vector<int> aux;
            aux.push_back(v[pos]);
            for(int i = 0; i < pos; i++){
                aux.push_back(v[i]);
            }
            if(aux > answ) swap(answ, aux);
        }
        for(auto x  : answ) cout << x << " ";
        cout << '\n';
    }
    return 0;
}