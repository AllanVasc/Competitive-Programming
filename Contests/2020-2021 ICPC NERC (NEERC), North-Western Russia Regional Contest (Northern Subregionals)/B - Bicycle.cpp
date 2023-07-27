#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, x, b, y, t;
    cin >> a >> x >> b >> y >> t;

    int ans1, ans2;
    ans1 = max(t - 30, 0LL) * x*21 + a;
    ans2 = max(t - 45, 0LL) * y*21 + b;

    cout << ans1 << " " << ans2 << "\n";

    return 0;
}