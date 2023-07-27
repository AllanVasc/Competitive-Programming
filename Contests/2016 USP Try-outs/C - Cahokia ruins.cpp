#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main(){
    int h, w;
    cin >> h >> w;

    vector <int> l(h), r(h);

    for(int i = 0; i < h; i++){
        cin >> l[i];
    }

    for(int i = 0; i < h; i++){
        cin >> r[i];
        r[i] = w - r[i];
    }

    int ans = 1e9;
    for(int i = 0; i <h; i++){
        ans = min(ans, r[i] - l[i]);
    }

    cout << setprecision(11) << fixed;
    cout << ans/2.0 << "\n";

    return 0;
}