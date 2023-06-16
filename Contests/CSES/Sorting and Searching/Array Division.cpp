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

bool check(int val, int k, vector<int> & v){
    // cout << "val = " << val << '\n';
    int n = v.size();
    vector<int> division;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(cnt + v[i] <= val) cnt += v[i];
        else{
            division.push_back(cnt);
            cnt = v[i];
        }
    }
    division.push_back(cnt);
    // cout << (division.size() <= k) << '\n';
    return division.size() <= k;
}
int32_t main() {
    optimize;
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int l = 0;
    for(int i = 0; i < n; i++) l = max(l, v[i]);
    // cout << "l = " << l << '\n';
    int r = 1e18;
    int answ = r;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(check(mid, k, v)){
            answ = min(answ, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << answ << '\n';
    return 0;
}