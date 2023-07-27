#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int mx = v[0];
    for(int i = 1; i < n; i++){
        mx = max(mx, v[i] - v[i - 1]);
    }
    // cout << mx << '\n';
    bool found = false;
    v.push_back(0);
    sort(v.begin(), v.end());
    n++;
    for(int i = 2; i < n; i++){
        if(v[i - 1] - v[i - 2] <= mx && v[i] - v[i - 2] <= mx) found = true;
    }

    if(found) cout << 0 << '\n';
    else cout << mx << '\n';
}