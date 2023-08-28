#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    int ans = 0;
    for(int i = 0; i < n; i++){
        char c;
        cin >> c;

        if(c == '6' || c == '8' || c == '0') continue;
        ans++;
    }

    cout << ans << "\n";

    return 0;
}