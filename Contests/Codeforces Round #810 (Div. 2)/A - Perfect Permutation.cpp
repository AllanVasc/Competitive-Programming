// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<int> v;
        v.assign(n,0);
        for(int i = 0; i < n-1; i++){
            v[i] = i+2;
        }
        v[n-1] = 1;

        for(int i = 0; i < n; i++) cout << v[i] << " ";
        cout << '\n';
    }

    return 0;
}