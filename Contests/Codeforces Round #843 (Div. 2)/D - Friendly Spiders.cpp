#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 3e5 + 5;
vector<int> factors(MAXN, 0);
void sieve(){
    factors[1] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!factors[i]){
            factors[i] = i;
            for(int j = i * i; j < MAXN; j += i){
                if(!factors[j]) factors[j] = i;
            }
        }
    }
}

vector<int> parent;
void bfs(vector<vector<int>> & g, int source){
    parent.assign(2 * MAXN, -1);

    queue<int> q;
    parent[source] = source;
    q.push(source);
    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto i : g[curr]){
            if(parent[i] == -1){
                parent[i] = curr;
                q.push(i);
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int source, target;
    cin >> source >> target;

    sieve();
    vector<vector<int>> g(2 * MAXN, vector<int>());
    for(int i = 0; i < n; i++){
        while(factors[v[i]] > 1){
            g[i].push_back(factors[v[i]] + MAXN);
            g[factors[v[i]] + MAXN].push_back(i);
            v[i] /= factors[v[i]];
        }
    }

    bfs(g, source - 1);

    if(parent[target - 1] == -1){
        cout << -1 << '\n';
    }
    else{
        vector<int> path;
        int curr = target - 1;
        path.push_back(target - 1);
        while(parent[curr] != curr){
            if(parent[curr] < MAXN) path.push_back(parent[curr]);
            curr = parent[curr];
        }

        cout << path.size() << '\n';
        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] + 1 << " ";
        }
        cout << '\n';
    }
    
    return 0;
}