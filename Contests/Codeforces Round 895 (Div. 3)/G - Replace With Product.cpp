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
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n), not1;
        int prod = 1;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(v[i] > 1) not1.push_back(i);
            prod = min(prod * v[i], 2 * n + 1);
        }
        if(prod > 2*n){
            int l = 0, r = n - 1;
            while(l < n && v[l] == 1) l++;
            while(r >= 0 && v[r] == 1) r--;
            cout << l + 1 << " " << r + 1 << '\n';
        }
        else{
            vector<int> ps(n + 1, 0), pp(n + 1, 1);
            for(int i = 1; i <= n; i++){
                ps[i] = ps[i - 1] + v[i - 1];
                pp[i] = pp[i - 1] * v[i - 1]; 
            }
            int answ = ps.back();
            int l = 0, r = 0;
            for(int i = 0; i < not1.size(); i++){
                for(int j = i + 1; j < not1.size(); j++){
                    int idx1 = not1[i];
                    int idx2 = not1[j];
                    int curr = ps.back() + pp[idx2 + 1] / pp[idx1] - (ps[idx2 + 1] - ps[idx1]);
                    if(curr > answ){
                        answ = curr;
                        l = idx1;
                        r = idx2;
                    }
                }
            }
            cout << l+1 << " " << r+1 << '\n';
        }

    }
    return 0;
}