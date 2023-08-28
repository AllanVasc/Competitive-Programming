#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("katryoshka.in", "r", stdin);
    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        int ans = 0;
        ans += min(n, min(m, k));
        n -= ans;
        m -= ans;
        k -= ans;

        ans += min(n/2, k);

        cout << "Case " << cs++ << ": " << ans << '\n';
    }
}