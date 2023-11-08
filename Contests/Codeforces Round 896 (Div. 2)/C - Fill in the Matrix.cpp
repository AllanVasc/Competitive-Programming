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

signed main() {
    // optimize;
    int t; 
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat;
        if(m > 1){
            while(mat.size() < n){
                int start = m - 1;
                while(start > 0 && mat.size() < n){
                    vector<int> curr(m, -1);
                    for(int i = 0, val = start; i < m; i++){
                        curr[i] =  val;
                        val++;
                        val %= m;
                    }
                    start--;
                    mat.push_back(curr);
                }
            }
        }
        else{
            mat.assign(n, vector<int>(m, 0));
        }
        set<int> answ;
        for(int i = 0; i < m; i++){
            set<int> mex;
            for(int j = 0; j < n; j++){
                mex.insert(mat[j][i]);
            }
            int curr = 0;
            while(mex.count(curr)) curr++;
            answ.insert(curr);
        }
        int beauty = 0;
        while(answ.count(beauty)) beauty++;
        cout << beauty << '\n';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << mat[i][j] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}