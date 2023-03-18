#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("hobz.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        bool has_zero = false;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') has_zero = true;
        }
        if(has_zero){
            cout << "YES" << '\n';
        }
        else if(n < 2){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }
    }
    return 0;
}