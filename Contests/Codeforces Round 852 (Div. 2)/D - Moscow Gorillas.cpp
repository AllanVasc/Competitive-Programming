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
    vector<int> pos_p(n + 1), pos_q(n + 1);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos_p[x] = i;
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos_q[x] = i;
    }

    int answ = 0;
    // MEX = 1
    int l = min(pos_p[1], pos_q[1]);
    int r = max(pos_p[1], pos_q[1]);
    answ += (l * (l + 1)) / 2;
    answ += ((n - 1 - r) * (n - 1 - r + 1)) / 2;
    answ +=  ((r - l - 1) * (r - l - 1 + 1)) / 2;

    l = n - 1, r = 0;
    for(int mex = 2; mex <= n; mex++){
        l = min({pos_p[mex - 1], pos_q[mex - 1], l});
        r = max({pos_p[mex - 1], pos_q[mex - 1], r});
        if((pos_p[mex] >= l && pos_p[mex] <= r) ||
           (pos_q[mex] >= l && pos_q[mex] <= r)) continue;

        int start = 0 , end = n - 1;
        if(pos_p[mex] < l) start = max(start, pos_p[mex] + 1);
        if(pos_q[mex] < l) start = max(start, pos_q[mex] + 1);
        if(pos_p[mex] > r) end = min(end, pos_p[mex] - 1);
        if(pos_q[mex] > r) end = min(end, pos_q[mex] - 1);
        // cout << "mex = " << mex << '\n';
        // cout << "l = " << l << " r = " << r << '\n';
        // cout << "start = " << start << " end = " << end << '\n';
        answ += (l - start + 1) * (end - r + 1);
    }
    // MEX = n + 1
    answ++;

    cout << answ << '\n';
    return 0;
}