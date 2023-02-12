#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 100;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> factors[MAXN];
    for(int i = 1; i < MAXN; i++){
        for(int j = i; j < MAXN; j += i){
            factors[j].push_back(i);
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int answ = INF;
        vector<int> freq(MAXN);
        int cnt = 0;
        int left = 0;
        for(int i = 0; i < n; i++){
            for(auto value : factors[v[i]]){
                if(value > m) break;
                if(freq[value] == 0) cnt++;
                freq[value]++;
            }
            while(cnt == m){
                answ = min(answ, v[i] - v[left]);
                for(auto value : factors[v[left]]){
                    if(value > m) break;
                    freq[value]--;
                    if(freq[value] == 0) cnt--;
                }
                left++;
            }
        }
        cout << (answ == INF ? -1 : answ) << '\n';
    }
    return 0;
}