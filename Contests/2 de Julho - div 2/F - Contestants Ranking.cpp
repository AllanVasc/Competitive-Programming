//  
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18; 
 
const int MAXN = 100*3 + 10;
 
vector<int> g[MAXN];
vector<int> pRank;
 
void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
}
 
void bfs(int source){
    vector<bool> visited(MAXN,false);
 
    queue<int> q;
    q.push(source);
    visited[source] = true;
    pRank[source] = 0;
 
    while(!q.empty()){
 
        int u = q.front();
        q.pop();
 
        for(auto i: g[u]){
            if(visited[i] == false){
                q.push(i);
                visited[i] = true;
                pRank[i] = pRank[u] + 1;
            }
        }
    }
}
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--){
        int q;
        cin >> q;
 
        map<string,int> name_int;
        map<int,string> int_name;
        int n = 1;
        int source = -1;
 
        for(int i = 0; i < q; i++){
            string p1,p2,p3;
            cin >> p1 >> p2 >> p3;
 
            if(name_int[p1] == 0){
                name_int[p1] = n;
                int_name[n] = p1;
                n++;
                if(p1 == "Ahmad"){
                    source = name_int[p1];
                }
            }
            if(name_int[p2] == 0){
                name_int[p2] = n;
                int_name[n] = p2;
                n++;
                if(p2 == "Ahmad"){
                    source = name_int[p2];
                }
            }
            if(name_int[p3] == 0){
                name_int[p3] = n;
                int_name[n] = p3;
                n++;
                if(p3 == "Ahmad"){
                    source = name_int[p3];
                }
            }
 
            addEdge(name_int[p1],name_int[p2]);
            addEdge(name_int[p1],name_int[p3]);
            addEdge(name_int[p2],name_int[p3]); 
        }
 
        // cout << "TENHO PESSOAS = " << n-1 << '\n';
        // cout << "SOURCE = " << source << '\n';
 
        pRank.assign(MAXN, -1);
 
        bfs(source);
 
        vector<pair<int, string>> answ;
        vector<pair<string,string>> answUnd;
 
        for(int i = 1; i < n; i++){
            if(pRank[i] != -1){
                answ.emplace_back(pRank[i], int_name[i]);
            }
            else{
                answUnd.emplace_back(int_name[i],"undefined");
            }
        }
 
        sort(answ.begin(), answ.end());
        sort(answUnd.begin(), answUnd.end());
 
        cout << n-1 << '\n';
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i].second << " " << answ[i].first << '\n';
        }
        for(int i = 0; i < answUnd.size(); i++){
            cout << answUnd[i].first << " " << answUnd[i].second << '\n';
        }
 
        for(int i = 0; i <= n; i++) g[i].clear();
    }
    return 0;
}