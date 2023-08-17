#include <bits/stdc++.h>

using namespace std;


#define int long long


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++) cin >> v[i];


    for(int k=2; k<=n; k++){
        if(n%k) continue;
        vector<int> cnt(k+1, 0);
        for(int i=0; i<n; i++){
            cnt[v[i]%k]++;
        }
        bool ok = true;
        for(int i=0; i<k; i++){
            if(cnt[i] != n/k) ok = false;
        }
        if(ok){
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}