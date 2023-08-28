#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, d;
    cin >> n >> d;

    vector <int> p(n);
    for(int i = 0; i < n; i++)
        cin >> p[i];
    
    sort(p.rbegin(), p.rend());

    int l = 0, r = n;
    int ans = 0;
    while(l < r){
        int value = p[l], acc = 1;
        l++;

        while(acc*value <= d && l < r){
            acc++;
            r--;
        }

        if(acc*value > d) ans++;
    }

    cout << ans << "\n";

    return 0;
}