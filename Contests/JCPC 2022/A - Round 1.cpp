#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("Round1.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 26){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
        }
    }
    return 0;
}