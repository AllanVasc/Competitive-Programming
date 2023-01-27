#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> v(n, vector<int>());
        map<int,int> freq;
        for(int i = 0; i < n; i++){
            int qtd;
            cin >> qtd;
            v[i].assign(qtd, 0);
            for(int j = 0; j < qtd; j++){
                cin >> v[i][j];
                freq[v[i][j]]++;
            }
        }

        bool has_answ = false;
        for(int i = 0; i < n; i++){
            bool check = true;
            for(int j = 0; j < v[i].size(); j++){
                if(freq[v[i][j]] == 1) check = false;
            }
            if(check) has_answ = true;
        }

        if(has_answ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}