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
        string s;
        cin >> s;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int answ = 0;
        for(int i = 0; i < n; i++){
            // cout << "i = " << i << " answ = " << answ << '\n';
            if(s[i] == '1') answ += v[i];
            if(i < n - 1 && s[i] == '0' && s[i + 1] == '1'){
                int minimo = v[i + 1];
                int pos = i + 1;
                int j;
                for(j = i + 1; j < n; j++){
                    if(s[j] == '0') break;
                    answ += v[j];
                    if(v[j] < minimo){
                        minimo = v[j];
                        pos = j;
                    }
                }
                if(v[i] > minimo){
                    answ -= minimo;
                    answ += v[i];
                }
                i = j - 1;
            }
        }
        cout << answ << '\n';
    }
    return 0;
}