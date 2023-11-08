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

int dist(pii a, pii b, int i, int j, int k){
    if(i < k && j < k) return 0;
    else{
        return abs(a.first - b.first) + abs(a.second - b.second);
    }
}
signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        a--, b--; // idxs
        vector<pii> v;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        pii closestA = {-1, -1};
        int distClosestA = INF;
        int idxClosestA = -1;
        for(int i = 0; i < k; i++){
            int val = dist(v[a], v[i], a, i, k);
            if(distClosestA > val){
                distClosestA = val;
                closestA = v[i];
                idxClosestA = i;
            }
        }
        pii closestB = {-1, -1};
        int distClosestB = INF;
        int idxClosestB = -1;
        for(int i = 0; i < k; i++){
            int val = dist(v[b], v[i], b, i, k);
            if(distClosestB > val){
                distClosestB = val;
                closestB = v[i];
                idxClosestB = i;
            }
        }
        int answ = min(dist(v[a], v[b], a, b, k), 
                       dist(v[a], closestA, a, idxClosestA, k) + 
                        dist(closestB, v[b], idxClosestB, b, k));

        cout << answ << '\n';
    }
    return 0;
}