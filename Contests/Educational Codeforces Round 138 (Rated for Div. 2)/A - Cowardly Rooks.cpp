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
        int n, m;
        cin >> n >> m;

        vector<vector<set<int>>> attack(n, vector<set<int>>(n, set<int>()));

        vector<ii> rooks;
        for(int i = 0; i < m; i++){
            int row, column;
            cin >> row >> column;
            row--;
            column--;
            rooks.push_back({row, column});
        }

        for(int i = 0; i < m; i++){
            auto [r, c] = rooks[i];

            attack[r][c].insert(-1);
            int curr = r + 1;
            while(curr < n){
                attack[curr][c].insert(i + 1);
                curr++;
            }
            curr = r - 1;
            while(curr >= 0){
                attack[curr][c].insert(i + 1);
                curr--;
            }
            curr = c + 1;
            while(curr < n){
                attack[r][curr].insert(i + 1);
                curr++;
            }
            curr = c - 1;
            while(curr >= 0){
                attack[r][curr].insert(i + 1);
                curr--;
            }
        }

        bool answ = false;

        for(int i = 0; i < m && !answ; i++){
            auto [r, c] = rooks[i];

            for(int curr = r + 1; curr < n; curr++){
                if(attack[curr][c].count(-1)) break;
                if(attack[curr][c].size() == 1) answ = true;
            }

            for(int curr = r - 1; curr >= 0; curr--){
                if(attack[curr][c].count(-1)) break;
                if(attack[curr][c].size() == 1) answ = true;
            }

            for(int curr = c + 1; curr < n; curr++){
                if(attack[r][curr].count(-1)) break;
                if(attack[r][curr].size() == 1) answ = true;
            }

            for(int curr = c - 1; curr >= 0; curr--){
                if(attack[r][curr].count(-1)) break;
                if(attack[r][curr].size() == 1) answ = true;
            }
        }
        if(answ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    
    return 0;
}