// B - Party
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

        vector<int> v(n+1,0);
        vector<int> degree(n+1,0);
        vector<ii> edges;
        for(int i = 1; i <= n; i++){
            degree[i] = 0;
            cin >> v[i];
        }

        for(int i = 0; i < m; i++){
            int u,v;
            cin >> u >> v;
            degree[u]++;
            degree[v]++;
            edges.push_back({u,v});
        }
        
        int answ = LONG_LONG_MAX;

        if(m%2 == 0){
            answ = 0;
        }
        else{
            for(int i = 1; i <= n; i++){
                if(degree[i]%2 == 1) answ = min(answ,v[i]);
            }

            for(int i = 0; i < m; i ++){
                if(degree[edges[i].first]%2 == 0 && degree[edges[i].second]%2 == 0) answ = min(answ,v[edges[i].first] + v[edges[i].second]);
            }
        }

        cout << answ << '\n';

    }

    return 0;
}