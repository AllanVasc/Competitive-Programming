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

bool check(vector<int> & v, int val, int sub){
    for(auto i : v){
        int dx = max(0LL, i - val);
        sub -= min(dx, sub);
    }
    return sub == 0;
}

int32_t main() {
    optimize;
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(ALL(v));
    while(q--){
        int k; cin >> k;

        int qttMinus = 0;
        int missOp = k - n;
        vector<int> increase;
        for(int i = k; i > k - n && i > 0; i--){
            increase.push_back(i);
        }
        if(k > n){
            if(missOp & 1){
                ++missOp;
                increase.pop_back();
            }
            qttMinus = missOp / 2; 
        }

        vector<int> cpV = v;
        for(int i = 0; i < increase.size(); i++){
            cpV[i] += increase[i];
        }

        int mn = cpV[0];
        int mx = cpV[0];
        for(int i = 0; i < n; i++){
            mn = min(mn, cpV[i]);
            mx = max(mx, cpV[i]);
        }
        int low = mn - qttMinus;
        int high = mn;
        int answ = low;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(check(cpV, mid, qttMinus)){
                answ = max(answ, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << answ << " ";
    }
    cout << '\n';
    return 0;
}