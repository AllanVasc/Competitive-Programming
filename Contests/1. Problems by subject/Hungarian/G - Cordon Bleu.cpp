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

// "n" needs to be the smallest dimension
template<typename T = int>
struct Hungarian{
    vector<vector<T>> a; // Matrix
    vector<T> u, v; // Potentials
    vector<int> p, way;
    int n, m;
    T inf;

    Hungarian(vector<vector<T>> & mat){
        n = mat.size();
        m = mat[0].size();
        a.assign(n + 1, vector<T>(m + 1, 0));
        u.assign(n + 1, 0);
        v.assign(m + 1, 0);
        p.assign(m + 1, 0);
        way.assign(m + 1, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i + 1][j + 1] = mat[i][j];
        inf = numeric_limits<T>::max();
    }

    // Returns {min assignment, v} 
    // v[i] = Chosen column of the i-th row
    pair<T, vector<int>> assignment(){
        for(int i = 1; i <= n; i++){
            p[0] = i;
            int j0 = 0;
            vector<int> minv(m + 1, inf);
            vector<bool> used(m + 1, false);
            do{
                used[j0] = true;
                int i0 = p[j0], j1 = -1;
                T delta = inf;
                for(int j = 1; j <= m; j++) if(!used[j]){
                    T cur = a[i0][j] - u[i0] - v[j];
                    if(cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta) delta = minv[j], j1 = j;
                }
                for(int j = 0; j <= m; j++){
                    if(used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                }
                j0 = j1;
            } while(p[j0] != 0);
            do{
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while(j0);
        }
        vector<int> answ(n + 1); // answ[1.. n]
        for(int j = 1; j <= m; j++) answ[p[j]] = j; // column in 1-based
        return make_pair(-v[0], answ);
    }
};

int Manhattan(pii a, pii b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}
signed main() {
    optimize;
    int n, m;
    cin >> n >> m;
    vector<pii> wines, bases;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        wines.push_back({x, y});
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        bases.push_back({x, y});
    }
    int xr, yr;
    cin >> xr >> yr;
    vector<vector<int>> v(n, vector<int>(m + n - 1, 0));
    for(int i = 0; i < v.size(); i++){
        auto [xw, yw] = wines[i];
        for(int j = 0; j < v[i].size(); j++){
            if(j < m){
                auto [x, y] = bases[j];
                v[i][j] = Manhattan({x, y}, {xw, yw}) + Manhattan({xw, yw}, {xr, yr});
            }
            else v[i][j] = 2 * Manhattan({xw, yw}, {xr, yr});
        }
    }
    Hungarian hungaro(v);
    cout << hungaro.assignment().first << '\n';
    return 0;
}