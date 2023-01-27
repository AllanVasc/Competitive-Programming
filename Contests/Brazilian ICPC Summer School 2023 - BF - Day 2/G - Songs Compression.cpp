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

    int n, m;
    cin >> n >> m;
    vector<iii> songs(n);
    int curr_total = 0;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        songs.push_back({a - b, a, b});
        curr_total += a;
    }

    sort(songs.begin(), songs.end(), greater<iii>());
    
    int answ = 0;
    for(int i = 0; i < n; i++){
        if(curr_total <= m) break;
        auto [dif,a , b] = songs[i];
        curr_total -= a;
        curr_total += b;
        answ++;
    }

    if(curr_total <= m){
        cout << answ << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}