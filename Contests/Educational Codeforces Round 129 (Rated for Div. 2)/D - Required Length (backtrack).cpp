#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int answ = INF;
map<uint64_t, int> processed;
void backtrack(uint64_t x, int steps, int target){
    if(processed.count(x) && processed[x] <= steps) return;
    processed[x] = steps;
    string s = to_string(x);
    int qtt = s.size();
    if(qtt == target){
        answ = min(answ, steps);
        return;
    }
    uint64_t aux = x;
    vector<int> freq(10, 0);
    while(aux){
        int curr = aux % 10;
        aux /= 10;
        freq[curr]++;
    }
    for(int i = 9; i >= 0; i--){
        if(freq[i]) backtrack(x * i, steps + 1, target);
    }
}

int32_t main() {
    optimize;
    
    int n; cin >> n;
    uint64_t x; cin >> x;
    backtrack(x, 0, n);
    cout << (answ == INF ? -1 : answ) << '\n';
    return 0;
}