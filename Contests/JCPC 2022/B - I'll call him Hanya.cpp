#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("hanya.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        bool neg = false;
        bool pos = false;
        for(int i =0; i < n; i++){
            if(v[i] < 0) neg = true;
            if(v[i] > 0) pos = true;
        }
        if(!neg && !pos){
            cout << 0 << '\n';
        }
        else if(neg && pos){
            cout << 2 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }
    return 0;
}