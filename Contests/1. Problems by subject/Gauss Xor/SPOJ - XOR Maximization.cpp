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
        for(int i = d - 1; i >= 0; i--){
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
    // Returns the smallest possible value of a vector
    // by subtracting a linear combination from the basis
    T reduce(T mask){
        for(int i = d - 1; i >= 0; i--){
            mask = min(mask, mask ^basis[i]);
        }
        return mask;
    }
    // Returns the largest possible value of a vector
    T augment(T mask){
        return ~reduce(~mask);
    }
    // Checks whether the vector can be formed by a linear combination of the basis
    bool check(T mask){
        for(int i = d - 1; i >= 0; i--){
            if((mask & (((T)1) << i)) == 0) continue;
            if(!basis[i]) return false;
            mask ^= basis[i];
        }
        return true;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    XorGauss<unsigned int> space(64);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        space.add(x);
    }
    cout << space.augment(0) << '\n';
    return 0;
}