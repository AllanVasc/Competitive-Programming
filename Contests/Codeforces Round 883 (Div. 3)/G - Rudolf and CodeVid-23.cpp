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

vector<int> days, removes, side;

int dijkstra(int src, int n){
    vector<int> dist(1 << n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});
    dist[src] = 0;
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        for(int i = 0; i < days.size(); i++){
            int nxt = u & removes[i] | side[i];
            if(dist[nxt] > dist[u] + days[i]){
                dist[nxt] = dist[u] + days[i];
                pq.push({dist[nxt], nxt});
            }
        }
    }

    return (dist[0] == INF ? -1 : dist[0]);
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s; cin >> s;
        int status = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') status |= (1 << i);
        }
        days.resize(m);
        removes.resize(m);
        side.resize(m);
        for(int i = 0; i < m; i++){
            cin >> days[i];
            cin >> s;
            int val = (1 << n) - 1;
            for(int j = 0; j < n; j++){
                if(s[j] == '1'){
                    val &= ~(1 << j);
                }
            }
            removes[i] = val;
            val = 0;
            cin >> s;
            for(int j = 0; j < n; j++){
                if(s[j] == '1'){
                    val |= (1 << j);
                }
            }
            side[i] = val;
        }

        cout << dijkstra(status, n) << '\n';
    }
    return 0;
}