//  A - Comunicating the Tibet
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 1e5 + 10;

vector<int> adj[MAXN];
bool visited[MAXN];

vector<int> numbers;
bool answer = true;

void addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsUtil(int v, int k){
    visited[v] = true;

    set<int> s;

    for(auto u: adj[v]){
        if(numbers[u] != 0) s.insert(numbers[u]);
    }


    if(s.size() >= k) answer = false;
    else{

        int possible = 1;

        for(auto i : s){
            if(i == possible){
                possible++;
            }
            else{
                break;
            }
        }

        numbers[v] = possible;

        for(auto u: adj[v]){
            if(visited[u] == false && answer)
                dfsUtil(u,k);
        }
    }
}

void dfs(int k){
    for(int i = 0; i < MAXN; i++){
        visited[i] = false;
    }
    for(int i = 0; i < MAXN; i++){
        if(visited[i] == false && answer)
            dfsUtil(i,k);
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,k;

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        addEdge(u-1,v-1);
    }

    numbers.assign(MAXN, 0);

    dfs(k);

    if(answer){
        for(int i = 0; i < n; i++){
            cout << numbers[i] << '\n';
        }
    }
    else{
        cout << "-1" << '\n';
    }

    return 0;
}
