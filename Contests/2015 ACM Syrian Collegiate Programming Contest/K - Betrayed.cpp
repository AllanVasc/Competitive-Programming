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

const int ms = 1e5 + 100;
vector<int> sz, good;
vector<int> dp, dist;

void precalc(int u, int p, vector<vector<int>>& g){
    for(auto v : g[u]){
        if(v == p) continue;
        precalc(v, u, g);
        dist[u] = max(dist[u], 1 + dist[v]);
        dp[u] = max(dp[u], dist[u]);
    }
}

void reroot(int u, int p, vector<vector<int>>& g, int k, int idx){
    if(dp[u] <= k) good[idx]++;
    ii best1 = {-1, -1};
    ii best2 = {-1, -1};
    for(auto v : g[u]){
        if(dp[v] >= best1.second){
            best2 = best1;
            best1 = {v, dp[v]};
        }
        else if(dp[v] > best2.second){
            best2 = {v, dp[v]};
        }
    }
    int backupU = dp[u];
    for(auto v : g[u]){
        if(v == p) continue;
        int backupV = dp[v];
        if(v != best1.first){
            dp[v] = max(dp[v], 1 + dp[u]);
        }
        else{
            dp[v] = max(dp[v], 2 + best2.second);
            dp[u] = max(0LL, 1 + best2.second);
        }
        reroot(v, u, g, k, idx);
        dp[u] = backupU;
        dp[v] = backupV;
    }
}

const double eps = 1e-9;

// "a" is the system matrix. The last column of this matrix is vector b
// 0    -> 0 solutions
// 1    -> 1 solution
// 2    -> INF solutions
int gauss(vector<vector<double>> a, vector<double>& answ){
    int n = (int) a.size();         // # equations
    int m = (int) a[0].size() - 1;  // # variables

    vector<int> where(m, -1);
    for(int col = 0, row = 0; col < m && row < n; col++){
        int sel = row;

        while(sel < n && abs(a[sel][col]) < eps) sel++;
        if(sel >= n) continue;

        where[col] = row;
        a[sel].swap(a[row]);

        for(int i = 0; i < n; i++){
            if(i != row){
                double c = a[i][col] / a[row][col];
                for(int j = col; j <= m; j++){
                    a[i][j] -= a[row][j] * c;
                }
            }
        }
        row++;
    }

    answ.assign(m, 0);
    for(int i = 0; i < m; i++){
        if(where[i] != -1)
            answ[i] = a[where[i]][m] / a[where[i]][i];
    }
    for(int i = 0; i < n; i++){
        double sum = 0;
        for(int j = 0; j < m; j++){
            sum += answ[j] * a[i][j];
        }
        if(abs(sum - a[i][m]) > eps) return 0;
    }
    for(int i = 0; i < m; i++){
        if(where[i] == -1) return 2;
    }
    return 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int cnt_tree, max_depth;
        cin >> cnt_tree >> max_depth;

        sz.assign(cnt_tree, 0);
        good.assign(cnt_tree, 0);
        for(int i = 0; i < cnt_tree; i++){
            int n;
            cin >> n;
            sz[i] = n;
            vector<vector<int>> g(n);
            for(int j = 1; j < n; j++){
                int u;
                cin >> u;
                u--;
                g[u].push_back(j);
                g[j].push_back(u);
            }
            dp.assign(n, 0);
            dist.assign(n, 0);
            precalc(0, 0, g);
            reroot(0, 0, g, max_depth, i);
        }
        // cout << "good: ";
        // for(auto x : good) cout << x << " ";
        // cout << '\n';

        vector<vector<double>> mat(cnt_tree + 1, vector<double>(cnt_tree + 1 + 1, 0));
        for(int i = 0; i < cnt_tree; i++){
            double pi = (1.0 * good[i]) / (1.0*sz[i]);
            mat[i][i] = 1;
            mat[i][i + 1] = -pi;
            mat[i][0] += (pi - 1);
        }
        mat[cnt_tree][cnt_tree] = 1;

        for(int i = 0; i < cnt_tree; i++){
            double pi = (1.0 * good[i]) / (1.0*sz[i]);
            mat[i][cnt_tree + 1] = 4 - (3.0 * pi);
        }
        mat[cnt_tree][cnt_tree + 1] = 0;

        // cout << "mat = " << '\n';
        // for(int i = 0; i < mat.size(); i++){
        //     for(int j = 0; j < mat[i].size(); j++){
        //         cout << mat[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        vector<double> answ(cnt_tree + 1);
        gauss(mat, answ);
        cout << fixed << setprecision(4);

        cout << answ[0] << '\n';
    }
    return 0;
}