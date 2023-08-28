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

const int ms = 3e3 + 100;
signed main() {
    optimize;
    int n, v;
    cin >> n >> v;
    vector<int> days(ms, 0);
    for(int i = 0; i < n; i++){
        int d, qtt;
        cin >> d >> qtt;
        days[d] += qtt;
    }
    int answ = 0;
    int missingLast = 0;
    for(int i = 0; i < ms; i++){
        int canPick = v;
        int fromOld = min(canPick, missingLast);
        answ += fromOld;
        canPick -= fromOld;
        int fromToday = min(canPick, days[i]);
        answ += fromToday;
        missingLast = days[i] - fromToday;
    }
    cout << answ << '\n';
    return 0;
}