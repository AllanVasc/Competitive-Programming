#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << max(a,b) * max(a,b) << '\n';
    }
    return 0;
}