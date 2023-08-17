#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n;
    cin >> n;

    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i] *= 2;
    }
    
    sort(v.begin(), v.end());

    int mx, mn, mid;
    mn = v.front();
    mx = v.back();
    mid = (mn + mx)/2;

    int ans = 0, diff = 1e18;
    for(int i = 0; i < n; i++){
        if(abs(v[i] - mid) < diff){
            diff = abs(v[i] - mid);
            ans = v[i];
        }
    }

    cout << ans/2 << "\n";

    return 0;
}