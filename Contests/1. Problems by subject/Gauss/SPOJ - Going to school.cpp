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

const double eps = 1e-9;

int gauss(vector<vector<double>> a, vector<double>& answ){
    int n = (int) a.size();         // # equations
    int m = (int) a[0].size() - 1;  // # variables

    vector<int> where(m, -1);
    for(int col = 0, row = 0; col < m && row < n; col++){
        int sel = row;
        for(int i = row; i < n; i++){
            if(abs(a[i][col]) > abs(a[sel][col])) sel = i;
        }
        if(abs(a[sel][col]) < eps) continue;
        for(int i = col; i <= m; i++){
            swap(a[sel][i], a[row][i]);
        }
        where[col] = row;

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
        int n, start, end;
        cin >> n >> start >> end;
        start--, end--;
        vector<vector<double>> values(n, vector<double>(n, 0));
        vector<double> sum(n, 0);

        for(int i = 0; i < n - 1; i++){
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            sum[u] += c;
            sum[v] += c;
            values[u][v] = c;
            values[v][u] = c;
        }

        if(start == end){
            cout << fixed << setprecision(5) << 0.0 << '\n';
        }
        else{
            vector<vector<double>> prob(n, vector<double>(n, 0));
            vector<vector<double>> id(n, vector<double>(n, 0));

            for(int i = 0; i < n; i++){
                id[i][i] = 1.0;
                for(int j = 0; j < n; j++){
                    if(i != end) prob[i][j] = values[i][j] / sum[i];
                    else{
                        if(j == end) prob[i][j] = 1.0;
                        else prob[i][j] = 0.0;
                    }
                }
            }

            vector<vector<double>> mat(n, vector<double>(n, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = id[i][j] - prob[i][j];
                }
            }

            vector<vector<double>> mx;
            for(int i = 0; i < n; i++){
                if(i != end){
                    vector<double> aux;
                    for(int j = 0; j < n; j++){
                        if(j != end) aux.push_back(mat[i][j]);
                    }
                    aux.push_back(1.0);
                    mx.push_back(aux);
                }
            }
            vector<double> answ;
            gauss(mx, answ);
            if(start > end) start--;
            cout << fixed << setprecision(5);
            cout << answ[start] << '\n';
        }
    }
    return 0;
}