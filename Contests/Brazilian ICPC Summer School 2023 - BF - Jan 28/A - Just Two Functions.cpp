#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;

int MOD;
const int m = 6;

class Matrix{
    public:
        ll mat[m][m] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
        Matrix operator * (const Matrix &p){
            Matrix ans;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < m; j++)
                    for(int k = ans.mat[i][j] = 0; k < m; k++)
                        ans.mat[i][j] = (ans.mat[i][j] + 1LL * (mat[i][k]%MOD) * (p.mat[k][j]%MOD)) % MOD;
            return ans;
        }
};

Matrix fexp(Matrix a, ll b){
    Matrix ans;
    for(int i = 0; i < m; i++)
        ans.mat[i][i] = 1;

    if(b < 0) return ans;

    while(b){
        if(b & 1) ans = ans*a;
        a = a*a;
        b >>= 1;
    }

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++){
        int a1, b1, c1;
        cin >> a1 >> b1 >> c1;

        int a2,b2,c2;
        cin >> a2 >> b2 >> c2;

        int f0, f1, f2;
        cin >> f0 >> f1 >> f2;

        int g0, g1, g2;
        cin >> g0 >> g1 >> g2;

        cin >> MOD;

        a1 %= MOD;
        a2 %= MOD;
        b1 %= MOD;
        b2 %= MOD;
        c1 %= MOD;
        c2 %= MOD;
        
        f0 %= MOD;
        f1 %= MOD;
        f2 %= MOD;

        g0 %= MOD;
        g1 %= MOD;
        g2 %= MOD;

        int q;
        cin >> q;
        cout << "Case " << cs << ":\n";
        while(q--){
            int n;
            cin >> n;

            Matrix ans;
            ans.mat[0][0] = f2;
            ans.mat[0][1] = g2;
            ans.mat[0][2] = f1;
            ans.mat[0][3] = g1;
            ans.mat[0][4] = f0;
            ans.mat[0][5] = g0;

            n -= 2;
            Matrix coef;
            coef.mat[0][0] = a1;
            coef.mat[0][2] = 1;

            coef.mat[1][1] = a2;
            coef.mat[1][3] = 1;
            coef.mat[2][0] = b1;
            coef.mat[2][4] = 1;

            coef.mat[3][1] = b2;
            coef.mat[3][5] = 1;

            coef.mat[4][1] = c2;

            coef.mat[5][0] = c1;

            coef = fexp(coef, n);

            ans = ans * coef;

            cout << ans.mat[0][0] % MOD << " " << ans.mat[0][1] % MOD << '\n';
        }
    }
   
    return 0;
}