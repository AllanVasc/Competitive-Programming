#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1e9 + 7;
const int ms = 1e6 + 5;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, b;
    cin >> n >> b;
    vector<int> v(n);
    vector<vector<int> > id(ms);
    for(int i=0; i<n; i++) {
        cin >> v[i];
        id[v[i]].push_back(i);
    }

    vector<int> ans(n, 0);

    for(int i=1; i<ms; i++){

        for(int j=0; j<id[i].size(); j++){
            int left = (id[i][j] -1 + n)%n, right = (id[i][j] + 1)%n;
            int l, r;
            l = (v[left] == i ? 0 : ans[left]);
            r = (v[right] == i ? 0 : ans[right]);
            ans[id[i][j]] = max(l + b, r + b);
        }
    }

    for(int i=0; i<n; i++) cout << ans[i] << (i+1 == n ? '\n' : ' ');

    return 0;
}
