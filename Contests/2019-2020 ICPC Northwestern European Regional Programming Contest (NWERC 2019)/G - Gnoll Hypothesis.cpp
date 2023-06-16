#include <bits/stdc++.h>

using namespace std;
#define int long long


long double dp[505][505];
// vector<long double> fat;
long double comb(int n, int k){
    return dp[n][k];
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    // fat.assign(505, 1);
    // for(int i = 1; i < fat.size(); i++){
    //     fat[i] = fat[i - 1] * i;
    // }

    dp[0][0] = 1;
    for(int i = 1; i < 505; i++){
        for(int j = 0; j <= i; j++){
            long double currSum = 0.0;
            dp[i][j] = dp[i - 1][j] + (j - 1 < 0 ? 0 : dp[i - 1][j - 1]);    
        }
    }
    int n, k;
    cin >> n >> k;
    vector<long double> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<long double> answ(n);
    if(k == 1){
        for(int i = 0; i < n; i++){
            cout << 100.0 / (1.0L * n) << " ";
        }
        cout << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++){
        long double pi = 0;
        for(int j = 0; j <= n - k; j++){
            pi += v[(i - j + n) % n];
            // cout << "pi = " <<  pi << '\n';
            answ[i] += pi * 1.0L * comb(n - 2 - j, k - 2);
        }
    }
    cout << setprecision(8) << fixed;
    for(int i = 0; i < n; i++){
        cout << answ[i] / ( 1.0L * comb(n, k))  << " "; 
    }
    cout << '\n';
}