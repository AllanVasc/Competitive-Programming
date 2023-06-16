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

int32_t main() {
    optimize;
    int n;
    cin >> n;
    set<int> answ;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    set<int> last;
    last.insert(v[0]);
    answ.insert(v[0]);
    for(int i = 1; i < n; i++){
        set<int> curr;
        for(auto j : last){
            int val = gcd(j, v[i]);
            curr.insert(val);
            answ.insert(val);
        }
        curr.insert(v[i]);
        answ.insert(v[i]);
        last = curr;
    }
    cout << answ.size() << '\n';
   
    return 0;
}