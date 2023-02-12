#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    vector<int> ps(n + 1);
    ps[0] = 0;
    for(int i = 0; i < n; i++){
        ps[i + 1] = ps[i] + v[i];
    }

    for(int i = 0; i < m; i++){
        int score;
        cin >> score;
        auto pos = lower_bound(v.begin(), v.end(), score + 1) - v.begin();
        // cout << "pos = " << pos << '\n';
        cout << ps[pos] + score * (n - pos) << '\n';
    }
    return 0;
}