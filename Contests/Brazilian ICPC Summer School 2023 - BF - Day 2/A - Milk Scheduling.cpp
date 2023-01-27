#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

static bool cmp(ii & a, ii & b){
    if(a.first != b.first) return a.first > b.first;
    return a.second > b.second;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    vector<ii> cows(n);
    for(int i = 0; i < n; i++){
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end(), cmp);
    vector<int> used(10000 + 10, false);
    int answ = 0;
    for(int i = 0; i < n; i++){
        auto [value, deadline] = cows[i];
        for(int j = deadline - 1; j >= 0; j--){
            if(used[j] == 0){
                answ += value;
                used[j] = true;
                break;
            }
        }
    }

    cout << answ << '\n';

    return 0;
}