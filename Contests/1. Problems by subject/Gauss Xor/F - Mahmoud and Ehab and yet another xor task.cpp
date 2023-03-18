#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

template<class T = unsigned int>
class XorGauss{
    public:
    int d, sz;
    vector<T> basis;
    XorGauss(int n) : d(n){
        basis.assign(d, 0);
        sz = 0;
    }
    bool add(T mask){
        for(int i = 0; i < d; i++){
            if((mask & (((T)1) << i)) == 0) continue;
            if(basis[i]) mask ^= basis[i];
            else{
                basis[i] = mask;
                sz++;
                return true;
            }
        }
        return false;
    }
    // Checks whether the vector can be formed by a linear combination of the basis
    bool check(T mask){
        for(int i = 0; i < d; i++){
            if((mask & (((T)1) << i)) == 0) continue;
            if(!basis[i]) return false;
            mask ^= basis[i];
        }
        return true;
    }
};

const int ms = 1e5 + 10;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> pw2(ms, 1);
    for(int i = 1; i < ms; i++){
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<vector<ii>> queries(n, vector<ii>());
    for(int i = 0; i < q; i++){
        int l, x;
        cin >> l >> x;
        queries[l - 1].push_back({x, i});
    }
    vector<int> answ(q);
    XorGauss space(20);
    for(int i = 0; i < n; i++){
        space.add(v[i]);
        for(auto [x, idx] : queries[i]){
            if(space.check(x)){
                answ[idx] = pw2[i + 1 - space.sz];
            }
            else{
                answ[idx] = 0;
            }
        }
    }
    for(int i = 0; i < q; i++) cout << answ[i] << '\n';
    return 0;
}