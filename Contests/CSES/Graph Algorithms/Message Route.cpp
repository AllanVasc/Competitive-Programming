#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
vector<int> pred;
bool bfs(int start, int end){
    queue<int> q;
    q.push(start);
    pred[start] = start;

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(curr == end){
            return true;
        }
        for(auto v : g[curr]){
            if(pred[v] == -1){
                pred[v] = curr;
                q.push(v);
            }
        }
    }

    return false;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    pred.assign(n, -1);
    if(bfs(0, n-1)){
        vector<int> answ;
        int curr = n - 1;
        while(curr != 0){
            answ.push_back(curr);
            curr = pred[curr];
        }
        answ.push_back(0);
        reverse(answ.begin(), answ.end());

        cout << answ.size() << '\n';
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i] + 1 << " ";
        }
        cout << '\n';
    }
    else{
        cout << "IMPOSSIBLE" << '\n';
    }


    return 0;
}