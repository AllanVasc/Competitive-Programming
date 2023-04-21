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
        vector<int> v(n - 1);
        for(int i = 0; i < n - 1; i++){
            cin >> v[i];
        }

        vector<int> answ(n, -1);
        for(int i = 0; i < v.size(); i++){
            if(answ[i] == -1) answ[i] = v[i];
            if(answ[i + 1] == -1) answ[i + 1] = v[i];
            
            answ[i] = min(answ[i], v[i]);
            answ[i + 1] = min(answ[i + 1], v[i]);
        }

        for(int i = 0; i < answ.size(); i++){
            cout << answ[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}