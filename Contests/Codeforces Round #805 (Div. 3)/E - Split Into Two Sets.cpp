// E - Split Into Two Sets
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 2*1e5 + 100;
vector<int> adj[MAXN];

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool isBipartite(int n){

    vector<int> color(n+1, -1);
    queue<ii> q;

    for(int i = 0; i < n; i++){

        if(color[i] == -1){
            q.push({i,0});
            color[i] = 0;

            while(!q.empty()){
                ii p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;
                for(int j: adj[v]){
                    if(color[j] == c) return false;
                    if(color[j] == -1){
                        color[j] = 1-c;
                        q.push({j, color[j]});
                    }
                }
            }
        }
    }
    return true;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        bool check = true;
        vector<int> freq(n+1,0);
        for(int i = 0; i < n; i++){
            int u, v;
            cin >> u >> v;
            freq[u-1]++;
            freq[v-1]++;
            if(freq[u-1] > 2 || freq[v-1] > 2) check = false;
            addEdge(u-1,v-1);
        }

        if(check){
            if(isBipartite(n)){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << "\n";
            }
        }
        else{
            cout << "NO" << '\n';
        }
        

        for(int i = 0; i < n;i++) adj[i].clear();
    }
    return 0;
}
