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

bool check(int cap, int hit, vi & v){
    // cout << "cap = " << cap << '\n';
    int n = v.size();
    int cnt = 0;
    int l = 0;
    int r = 0;
    map<int,int> freq;
    int unique = 0;
    while(r < n){
        if(freq[v[r]] > 0) cnt++; // HIT
        freq[v[r]]++;
        if(freq[v[r]] == 1) unique++;
        while(l < r && unique > cap){
            freq[v[l]]--;
            if(freq[v[l]] == 0) unique--;
            l++;
        }

        r++;
    }

    return cnt >= hit;
}

int32_t main() {
    optimize;
    
    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 1;
    int r = n;
    int answ = INF;
    // cout << check(3, k, v) << '\n';
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid, k,  v)){
            answ = min(answ, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << (answ == INF ? "cbddl" : to_string(answ)) << '\n';
    return 0;
}