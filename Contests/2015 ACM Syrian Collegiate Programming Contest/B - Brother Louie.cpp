#include <bits/stdc++.h>
using namespace std;
  
#define int long long
#define double long double

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> depth;
vector<pair<double,double>> info;
vector<int> order;

void findOrder(int u){
    bool is_leaf = true;
    for(auto v : g[u]){
        is_leaf = false;
        depth[v] = depth[u] + 1;
        findOrder(v);
    }
    if(is_leaf) order.push_back(u);
}

pair<double,double> fillCoord(int u){
    if(g[u].size() == 0) return info[u];
    pair<double,double> left = fillCoord(g[u][0]);
    pair<double,double> right = fillCoord(g[u][1]);

    auto [cnt_r_l, cnt_h_l] = left;
    auto [cnt_r_r, cnt_h_r] = right;

    pair<double,double> dist = {cnt_r_r - cnt_r_l, 
                                cnt_h_r - cnt_h_l}; 

    info[u] = {cnt_r_l + (dist.first / 2.0), cnt_h_l + (dist.second / 2.0)};
    return info[u];
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        g.assign(n, vector<int>());
        vector<int> degree(n, 0);
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            if(k){
                int l, r;
                cin >> l >> r;
                l--, r--;
                g[i].push_back(l);
                g[i].push_back(r);
                degree[l]++;
                degree[r]++;
            }
        }

        int root = -1;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0) root = i;
        }
        depth.assign(n, 0);
        info.assign(n, {0,0});
        order.clear();

        findOrder(root);
        info[order[0]] = {0, 0};
        for(int i = 1; i < order.size(); i++){
            int u = order[i];
            auto [cnt_r, cnt_h] = info[order[i - 1]];
            info[u] = {cnt_r + 2, cnt_h + 1};
        }
        
        pair<double,double> rootCoord = fillCoord(root);
        // cout << rootCoord.first << " " << rootCoord.second << '\n';

        while(q--){
            int r, v, h ,u;
            cin >> r >> v >> h >> u;
            u--;

            cout << fixed << setprecision(4);
            double x = r * (info[u].first - rootCoord.first) + h * (info[u].second - rootCoord.second);
            double y = -(2 * r * depth[u] + v * depth[u]);
            cout << x << " " << y << '\n';
        }
    }
    return 0;
}