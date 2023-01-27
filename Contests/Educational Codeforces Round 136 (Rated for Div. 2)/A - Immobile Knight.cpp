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
    
    int t;
    cin >> t;

    while(t--){

        int n,m;
        cin >> n >> m;

        vector<vector<int>> mat;
        mat.assign(n, vector<int>(m,1));

        vector<ii> dir = { {-1,-2}, {1,-2}, {2,-1}, {2,1}, {-1,2}, {1,-2}, {-2,-1}, {-2,1}};
        
        ii answ = {0,0};
        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < m; j++){
                bool check = false;
                for(auto k : dir){
                    int rc = i + k.first;
                    int cc = j + k.second;

                    if(rc < 0 || rc >= n || cc < 0 || cc >= m) continue;
                    check = true;
                }
                if(!check) answ = {i,j};
            }
        }

        cout << answ.first+1 << " " << answ.second+1 << '\n';
    }
    return 0;
}