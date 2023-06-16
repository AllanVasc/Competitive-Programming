#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());
    while(q--){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            // update
            int val;
            cin >> val;

            auto itr = lower_bound(v.begin(), v.end(), val);
            if(itr == v.end()){
                v.push_back(val);
            }
            else if(*itr == val) continue;
            else{
                int pos = itr - v.begin();
                v[pos] = val;
            }
        }
        else{
            int a, b;
            cin >> a >> b;
            int cnt = upper_bound(v.begin(), v.end(), b) - 
                      lower_bound(v.begin(), v.end(), a);
            cout << cnt << '\n';
        }
    }
    return 0;
}