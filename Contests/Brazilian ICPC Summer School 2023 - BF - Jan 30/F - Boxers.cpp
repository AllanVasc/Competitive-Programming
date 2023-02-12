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

    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    map<int,int> freq;

    int answ = 0;
    for(int i = 0; i < n; i++){
        if(v[i] - 1 > 0 && freq[v[i] - 1] == 0){
            answ++;
            freq[v[i] - 1] = 1;
        }
        else if(freq[v[i]] == 0){
            answ++;
            freq[v[i]] = 1;
        }
        else if(freq[v[i] + 1] == 0){
            answ++;
            freq[v[i] + 1] = 1;
        }
    }
    cout << answ << '\n';
    return 0;
}