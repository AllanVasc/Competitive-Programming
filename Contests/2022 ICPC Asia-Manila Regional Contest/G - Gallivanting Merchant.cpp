#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    
    int add = 0;
    vector <pair <int, int>> ev;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;

        if(r - l >= k - 1){
            add++;
            continue;
        }

        l %= k;
        r %= k;

        if(l > r){
            ev.emplace_back(0, 0);
            ev.emplace_back(r, 1);

            ev.emplace_back(l, 0);
            ev.emplace_back(k - 1, 1);
        }

        else{
            ev.emplace_back(l, 0);
            ev.emplace_back(r, 1);
        }
    }

    sort(ev.begin(), ev.end());

    int active = 0, bAns = 0;
    for(auto [day, type] : ev){
        if(type){
            bAns = max(bAns, active);
            active--;
        }
        else active++;
    }

    cout << bAns + add << "\n";

    return 0;
}