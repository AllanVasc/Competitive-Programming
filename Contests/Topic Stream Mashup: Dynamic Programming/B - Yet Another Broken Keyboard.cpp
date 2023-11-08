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
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    set<char> z;
    string aux; 
    cin.ignore();
    getline(cin, aux);
    for(int i = 0; i < aux.size(); i++){
        if(i & 1) continue;
        z.insert(aux[i]);
    }
    int answ = 0;
    for(int l = 0; l < n; l++){
        if(z.count(s[l]) == 0) continue;
        int r = l;
        while(r < n && z.count(s[r])) r++;
        // cout << "l = " << l << " r = " << r << '\n';
        answ += (r - l + 1) * (r - l) / 2;
        l = r;
    }
    cout << answ << '\n';
    return 0;
}