#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    optimize;
    
    ll n, x;
    cin >> n >> x;
    queue<ll> q;
    map<ll,ll> dist;
    dist[x] = 0;
    q.push(x);
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        string s = to_string(cur);
        if(s.size() == n){
            cout << dist[cur] << '\n';
            return 0;
        }
        for(auto x : s){
            if(x == '0') continue;
            ll next = cur * int(x - '0');
            if(!dist.count(next)){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}