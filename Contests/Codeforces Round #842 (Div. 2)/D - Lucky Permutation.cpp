#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> dsu;
vector<int> sizes;
void build(int n){
    dsu.assign(n + 1, 0);
    sizes.assign(n + 1, 1);
    for(int i = 0; i <= n; i++) dsu[i] = i;
}

int Find(int u){
    if(dsu[u] == u) return u;
    return dsu[u] = Find(dsu[u]);
}

void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u != v){
        if(sizes[u] < sizes[v]) swap(u, v);
        dsu[v] = u;
        sizes[u] += sizes[v];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        build(n);
        for(int i = 0; i < n; i++){
            Union(i + 1, v[i]);
        }
        set<int> st;
        for(int i = 1; i <= n; i++) st.insert(Find(i));
        int cycles = st.size();

        int answ = n + 1;
        for(int i = 0; i < n - 1; i++){
            int curr = 0;
            if(Find(v[i]) == Find(v[i + 1])) curr = cycles + 1;
            else curr = cycles - 1;

            answ = min(answ, n - curr);
        }
        cout << answ << '\n';
    }
    return 0;
}