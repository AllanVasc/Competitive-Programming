#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; 
    cin >> n;
    vector<int> v(n);
    int total = 0;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> ps(n + 1, 0);
    for(int i = 1; i <= n; i++){
        total += v[i - 1];
        ps[i] = ps[i - 1] + v[i - 1];
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        auto pos = lower_bound(v.begin(), v.end(), x) - v.begin();

        int answ = total - (n - pos) * x - ps[pos];
        cout << answ << '\n';
    }
    return 0;
}