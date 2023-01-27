//  B - New Job
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
        int n,m;
        cin >> n >> m;
 
        int answ = 0;
        int ok = 0;
        for(int factor = 1; factor < m; factor*=2){
            ok += factor;
            answ++;
            if(ok >= n) break;
        }
 
        if(ok >= n){
            cout << answ << '\n';
        }
        else{
            answ += (n-ok+m-1)/m;
 
            cout << answ << '\n';
        }
 
 
    }
    return 0;
}
