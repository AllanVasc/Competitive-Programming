//  C - Train and Queries
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
 
        int n,k;
        cin >> n >> k;
 
        vector<int> v;
 
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }
 
        map<int,int> f_occ;
        map<int,int> l_occ;
        for(int i = 0 ; i < n; i++){
            if(f_occ[v[i]] == 0)
                f_occ[v[i]] = i+1;
 
            l_occ[v[i]] = i+1;
        }
 
        for(int i = 0; i < k; i++){
            int ql,qr;
            cin >> ql >> qr;
 
            if(f_occ[ql] == 0 || f_occ[qr] == 0) cout << "NO\n";
            else if(f_occ[ql] < l_occ[qr]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}