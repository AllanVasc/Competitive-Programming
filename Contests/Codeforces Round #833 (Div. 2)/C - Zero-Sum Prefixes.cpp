#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v(n);
        
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<int> ps(n, 0);
        
        ps[0] = v[0];
        for(int i = 1; i < n; i++) ps[i] = ps[i - 1] + v[i];

        int answ = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == 0){
                map<int,int> freq;
                freq[ps[i]]++;
                int most = 1;
                for(int j = i + 1; j < n; j++){
                    if(v[j] == 0){
                        i = j - 1;
                        break;
                    }
                    freq[ps[j]]++;
                    most = max(most, freq[ps[j]]);
                    if(j == n - 1) i = j;
                }
                answ += most;
            }
            else{
                if(ps[i] == 0) answ++;
            }
        }

        cout << answ << '\n';

    }
    return 0;
}