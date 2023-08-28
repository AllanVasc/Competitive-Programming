#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> even, odd;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(x % 2) odd.push_back(x);
        else even.push_back(x);
    }
    if(odd.size() < k - p){
        cout << "NO" << '\n';
        return 0;
    }
    int pointer = p;
    vector<vector<int>> groups(k);
    while(pointer != k){
        groups[pointer].push_back(odd.back());
        odd.pop_back();
        pointer++;
    }
    pointer = 0;
    while(odd.size() >= 2 && pointer != p){
        groups[pointer].push_back(odd.back());
        odd.pop_back();
        groups[pointer].push_back(odd.back());
        odd.pop_back();
        pointer++;
    }
    while(!even.empty() && pointer != p){
        groups[pointer].push_back(even.back());
        even.pop_back();
        pointer++;
    }
    if(pointer != p || (odd.size() % 2)){
        cout << "NO" << '\n';
        return 0;
    }
    while(!odd.empty()){
        groups[0].push_back(odd.back());
        odd.pop_back();
    }
    while(!even.empty()){
        groups[0].push_back(even.back());
        even.pop_back();
    }
    cout << "YES" << '\n';
    for(int i = 0; i < groups.size(); i++){
        cout << groups[i].size() << " ";
        for(auto x : groups[i]) cout << x << " ";
        cout << '\n';
    }
    return 0;
}