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

string s;
vector<vector<int>> ps;
int solve(int n, int sec, int th){
    int cnt1 = ps[0][n];
    int cnt2 = ps[sec][n];
    int cnt3 = ps[th][n];
    int answ = INF;
    for(int i = 0; i < n; i++){
        int miss = 0;
        miss += cnt1 - (ps[0][i + cnt1] - ps[0][i]);
        miss += cnt2 - (ps[sec][i + cnt1 + cnt2] - ps[sec][i + cnt1]);
        miss += cnt3 - (ps[th][i + cnt1 + cnt2 + cnt3] - ps[th][i + cnt1 + cnt2]);
        answ = min(answ, miss);
    }

    return answ;
}

signed main() {
    optimize;
    int n; cin >> n;
    cin >> s;
    s += s;
    int answ = INF;
    ps.assign(3, vector<int>(s.size() + 1, 0));
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= s.size(); j++){
            ps[i][j] = ps[i][j - 1] + (s[j - 1] == ('A' + i));
        }
    }
    cout << min(solve(n, 1, 2), solve(n, 2, 1)) << '\n';
    return 0;
}