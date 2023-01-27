#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 5*1e4 + 10;
const int BLOCK = 225;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,q;
    cin >> n >> q;
    
    vector<int> v;
    v.assign(n, 0);
    
    vector<vector<int>> occ;
    occ.assign(MAXN, vector<int>());

    for(int i = 0; i < n; i++){
        cin >> v[i];
        occ[v[i]].push_back(i+1);
    }

    map<int, map<int,vector<int>>> check;

    // check[m][x]
    for(int i = 1; i < BLOCK; i++){
        for(int j = 0; j < n; j++){
            check[i][v[j] % i].push_back(j+1);
        }
    }

    while(q--){
        int l,r,x,m;
        cin >> l >> r >> x >> m;

        int answ = 0;
        if(m < BLOCK){
            answ = upper_bound(check[m][x].begin(), check[m][x].end(), r) - lower_bound(check[m][x].begin(), check[m][x].end(), l);
        }
        else{
            for(int k = 0; k + x < MAXN; k += m){
                answ += upper_bound(occ[k+x].begin(), occ[k+x].end(), r) - lower_bound(occ[k+x].begin(), occ[k+x].end(), l);
            }
        }

        cout << answ << '\n';
    }
    return 0;
}