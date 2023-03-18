#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("dotak.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        n = (n * k) % (k + 1);
        if(n == k){
            cout << "Omda" << '\n';
        }
        else{
            if(n % 2 == 1) cout << "Omda" << '\n';
            else cout << "Teemo" << '\n';
        }
    }
    return 0;
}