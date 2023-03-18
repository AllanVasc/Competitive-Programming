#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> v;
int count(int k){
    int n = v.size();
    int l = 0, r = 0;
    unordered_map<int, int> freq;
    int answ = 0;
    int diff = 0;
    while(r < n){
        freq[v[r]]++;
        if(freq[v[r]] == 1) diff++;
        while(diff > k){
            freq[v[l]]--;
            if(freq[v[l]] == 0) diff--;
            l++;
        }
        answ += (r - l + 1);
        r++;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    int lessk = count(k);
    int lessk1 = count(k - 1);

    cout << lessk - lessk1 << '\n';
    return 0;
}