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
    vector<int> basis;
    XorGauss(int n) : d(n){
        basis.assign(d, 0);
        sz = 0;
    }
    T reduce(T mask) {
        for(int i = d - 1; i >= 0; i--) {
            mask = min(mask, mask ^ basis[i]);
        }
        return mask;
    }
    void add(T mask){
        for(int i = d - 1; i >= 0; i--){
            if((mask & (((T)1) << i)) == 0) continue;
            if(basis[i] == 0){
                basis[i] = mask;
                sz++;
                break;
            }
            mask ^= basis[i];
        }
    }
    int query(T curr, int k){
        curr = reduce(curr);
        for(int i = d - 1; i >= 0; i--){
            if((curr ^ basis[i]) <= k) curr = max(curr ^ basis[i], curr);
            else{
                int aux = curr ^ basis[i];
                for(int j = i - 1; j >= 0; j--){
                    aux = min(aux ^ basis[j], aux);
                    if(aux <= k){
                        curr = aux;
                        break;
                    }
                }
            }
        }
        return (curr <= k ? curr : 0);
    }

    /*
    int query(T curr, int k){
        curr = reduce(curr);
        for(int i = d - 1; i >= 0; i--){
            if(((curr >> i) & (T)1)) continue;
            if((curr ^ basis[i]) <= k) curr = curr ^ basis[i];
            else{
                int aux = curr ^ basis[i];
                for(int j = i - 1; j >= 0; j--){
                    if((aux & (((T)1) << j)) == 0) continue;
                    aux = aux ^ basis[j];
                    if(aux <= k){
                        curr = aux;
                        break;
                    }
                }
            }
        }
        return (curr <= k ? curr : 0);
    }
    */
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("salkan.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n), b(n);
        int cur = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            cur ^= a[i];
        }
        XorGauss space(30);
        for(int i = 0; i < n; i++){
            cin >> b[i];
            space.add(a[i] ^ b[i]);
        }
        cout << space.query(cur, k) << '\n';
    }
    return 0;
}