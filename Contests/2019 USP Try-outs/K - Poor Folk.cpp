#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int ps = 0;
    for(int i = 0; i < n; i++){
        if(v[i] <= ps + 1){
            ps += v[i];
        }
        else{
            cout << ps + 1 << '\n';
            return 0;
        }
    }

    cout << ps + 1 << '\n';


    return 0;
}