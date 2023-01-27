// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, s, m;
    cin >> n >> s >> m;

    vector<int> v;
    v.assign(n, 0);
    for(int i = 0 ; i < n; i++) cin >> v[i];
    s--;

    set<int> indices;

    int jumps = 0;
    while(1){
        
        // cout << "s = " << s << '\n';

        if(s < 0){
            cout << "left" << '\n';
            cout << jumps << '\n';
            return 0;
        }

        if(s >= n){
            cout << "right" << '\n';
            cout << jumps << '\n';
            return 0;
        }

        if(m == v[s]){
            cout << "magic" << '\n';
            cout << jumps << '\n';
            return 0;
        }

        if(indices.count(s) != 0){
            cout << "cycle" << '\n';
            cout << jumps << '\n';
            return 0;
        }

        indices.insert(s);

        s = s + v[s];
        jumps++;
    }


    return 0;
}