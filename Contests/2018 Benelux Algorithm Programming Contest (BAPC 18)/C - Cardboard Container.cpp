#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <int> div(int n){
    vector <int> ans;
    for(int i = 1; i*i <= n; i++){
        if(n%i) continue;
        ans.push_back(i);
        if(i*i != n) ans.push_back(n/i);
    }

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1){
        cout << "6\n";
        return 0;
    }

    vector <int> divisors = div(n);
    long long ans = 1e16;
    for(int i = 0; i < divisors.size(); i++){
        int a = divisors[i];
        for(int j = 0; j < divisors.size(); j++){
            int b = divisors[j];
            if(n % (a*b)) continue;

            int c = n / (a*b);
            ans = min(ans, 1LL*(2*a*b + 2*a*c + 2*b*c));
        }
    }

    cout << ans << "\n";
    return 0;
}