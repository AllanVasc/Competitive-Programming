#include <bits/stdc++.h>

using namespace std;

#define int long long

int digit_sum(int a){
    int ans = 0;
    while(a){
        ans += a % 10;
        a/=10;
    }

    return ans;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("digits.in", "r", stdin);
    freopen("digits.out", "w", stdout);

    vector <vector <int>> v(1e6);
    int ans = 1e18;

    int n;
    cin >> n;

    for(int i = 1; i < 1e6; i++){
        int aux = digit_sum(i);
        v[aux].push_back(i);

        if(v[aux].size() == n){
            int sum = 0;
            for(int i = 0; i < n; i++)
                sum += v[aux][i];
            ans = min(sum, ans);
        }
    }

    cout << ans << "\n";
}