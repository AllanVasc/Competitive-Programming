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
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int answ = 0;
    int dif = 0;
    map<int,int> freq;
    for(int left = 0, right = -1; left < n; left++){
        while(right < n && dif <= k){
            right++;
            if(freq[v[right]] == 0) dif++;
            freq[v[right]]++;
        }
        answ += right - left;
        freq[v[left]]--;
        if(freq[v[left]] == 0) dif--;
    }

    cout << answ << '\n';
    return 0;
}