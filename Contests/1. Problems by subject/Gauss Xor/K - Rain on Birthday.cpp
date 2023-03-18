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
    void add(T mask){
        for(int i = d - 1; i >= 0; i--){
            if((mask & (((T)1) << i)) == 0) continue;
            if(basis[i]){
                mask ^= basis[i];
            }
            else{
                basis[i] = mask;
                sz++;
                break;
            }
        }
    }
    bool check(T mask){
        for(int i = d - 1; i >= 0; i--){
            if((mask & (((T)1) << i)) == 0) continue;
            if(!basis[i]) return false;
            mask ^= basis[i];
        }
        return true;
    }
    bool query(T a, T b){
        XorGauss new_space(d);
        for(int i = d - 1; i >= 0; i--){
            new_space.add(basis[i] & a);
        }
        return new_space.check(b);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int q;
    cin >> q;
    XorGauss space(30);
    while(q--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int c;
            cin >> c;
            space.add(c);
        }
        else{
            int a, b;
            cin >> a >> b;
            if(space.query(a, b)){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}