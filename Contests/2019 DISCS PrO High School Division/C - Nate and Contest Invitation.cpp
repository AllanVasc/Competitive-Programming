// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> g;
int dfs(vector<int>& visited, int vtx){
    visited[vtx] = true;
    int answ = 0;

    for(auto i : g[vtx]){
        if(!visited[i]) answ += dfs(visited, i);
    }
    return answ + 1;
}


vector<int> dfsUTIL(){
    vector<int> visited(g.size(), 0);

    vector<int> component;
    for(int i = 0; i < g.size(); i++){
        int count = 0;
        if(!visited[i]){
            count = dfs(visited, i);
        }
        component.push_back(count);
    }

    return component;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    g.assign(n, vector<int>());

    map<string,int> mp;
    int qtd = 0;

    for(int i = 0; i < m; i++){
        string s1,s2;
        cin >> s1 >> s2;

        if(mp.find(s1) == mp.end()){
            mp[s1] = qtd;
            qtd++;
        }
        if(mp.find(s2) == mp.end()){
            mp[s2] = qtd;
            qtd++;
        }

        g[mp[s1]].push_back(mp[s2]);
        g[mp[s2]].push_back(mp[s1]);
    }

    // for(int i = 0; i < n; i++){
    //     cout << i << " = ";
    //     for(int j = 0; j < g[i].size(); j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    vector<int> components = dfsUTIL();
    sort(components.begin(), components.end());
    int answ = 0;
    for(int i = components.size() - 1; i >= 0; i--){
        if(k){
            answ += components[i];
            k--;
        }
    }

    cout << answ << '\n';

    return 0;
}