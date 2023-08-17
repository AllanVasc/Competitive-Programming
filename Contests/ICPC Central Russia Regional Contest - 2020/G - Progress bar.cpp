#include <bits/stdc++.h>

using namespace std;

#define int long long


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int k1, k2;
    cin >> k1 >> k2;


    int x = 3*k1, y = 2*k2;


    set<int> ans;
    if(x-1 == y || x-1 == y-1) ans.insert(x-1);
    if(x == y || x == y-1) ans.insert(x);
    if(x+1 == y || x+1 == y-1) ans.insert(x+1);

    if(ans.empty()){
        cout << "0\n";
    }
    else{
        for(int x : ans) cout << x << " ";
        cout << '\n';
    }


    return 0;
}