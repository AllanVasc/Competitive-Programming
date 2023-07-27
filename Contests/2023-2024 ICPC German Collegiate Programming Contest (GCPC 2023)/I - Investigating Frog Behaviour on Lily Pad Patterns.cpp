#include <bits/stdc++.h>

using namespace std;
// #define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    set <int> free;
    for(int i = 1; i <= 2e6; i++) free.emplace(i);

    int n;
    cin >> n;

    vector <int> frogs(n);
    for(int i = 0; i < n; i++){
        cin >> frogs[i];
        
        free.erase(frogs[i]);
    }

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;

        x--;

        auto it = free.upper_bound(frogs[x]);
        cout << *it << "\n";

        free.emplace(frogs[x]);
        free.erase(it);

        frogs[x] = *it;
    }

    return 0;
}