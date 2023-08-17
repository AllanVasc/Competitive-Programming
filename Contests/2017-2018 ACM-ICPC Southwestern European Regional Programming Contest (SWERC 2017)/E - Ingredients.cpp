#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tiii tuple<int,int,int>
const int INF = 1e12;

vector<vector<tiii>> g; // {id[deri], cost, prest}
vector<int> cost, prest;

void dijkstra(vector<int> bases){
    int n = g.size();
    cost.assign(n, INF);
    prest.assign(n, 0);
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;   // cost, -prest, id
    for(int i = 0; i < bases.size(); i++){
        pq.push({0, 0, bases[i]});
        cost[bases[i]] = 0;
    }
    while(!pq.empty()){
        auto[du, pu, u] = pq.top();
        pq.pop();
        if(du > cost[u]) continue;
        for(auto [v, c, win] : g[u]){
            if(cost[v] > cost[u] + c){
                cost[v] = cost[u] + c;
                prest[v] = prest[u] + win;
                pq.push({cost[v], -prest[v], v});
            }
            else if(cost[v] == cost[u] + c && prest[u] + win > prest[v]){
                cost[v] = cost[u] + c;
                prest[v] = prest[u] + win;
                pq.push({cost[v], -prest[v], v});
            }
        }
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int budget; 
    cin >> budget;
    int n; 
    cin >> n;
    vector<tuple<string, string, int, int>> menu;
    for(int i = 0; i < n; i++){
        string s1, s2, lixo;
        int cost, p;
        cin >> s1 >> s2 >> lixo >> cost >> p;
        // cout << s1 << " " << s2 << " " << lixo << '\n';
        menu.emplace_back(s1, s2, cost, p);
    }
    map<string, int> id;
    vector<int> bases;
    for(int i = 0; i < n; i++){
        auto[deri, base, cost, p] = menu[i];
        if(id.count(deri) == 0){
            // cout << deri << " id = " << id.size() << '\n';
            id[deri] = id.size();
        }
    }
    for(int i = 0; i < n; i++){
        auto[deri, base, cost, p] = menu[i];
        if(id.count(base) == 0){
            id[base] = id.size();
            bases.push_back(id[base]);
        }
    }
    // compressao ok, montar grafo
    g.assign(id.size(), vector<tiii>());
    for(int i = 0; i < n; i++){
        auto[deri, base, cost, p] = menu[i];
        g[id[base]].emplace_back((int) id[deri], cost, p);
    }
    // cout << "bases:" << '\n';
    // for(int i = 0; i < bases.size(); i++){
    //     cout << bases[i] << '\n';
    // }
    dijkstra(bases);
    // cout << "cost" << '\n';
    // for(int i = 0; i < id.size(); i++){
    //     cout << cost[i] << " ";
    // }
    // cout << '\n';
    // cout << "prest" << '\n';
    // for(int i = 0; i < id.size(); i++){
    //     cout << prest[i] << " ";
    // }
    // cout << '\n';
    // Agora dp
    vector<pair<int,int>> v; // cost, prestige
    for(int i = 0; i < cost.size(); i++){
        v.push_back({cost[i], prest[i]});
    }
    vector<int> dp(budget + 5, -1);
    dp[0] = 0;
    for(int i=0; i< v.size(); i++){
        for(int j=budget; j>=v[i].first; j--){
            if(dp[j - v[i].first] == -1) continue;
            dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
        }
    }

    int ans = -1;
    int val = -1;
    for(int i=0; i<=budget; i++){
        if(ans < dp[i]){
            ans = dp[i];
            val = i;
        }
    }
    cout << ans << endl;
    cout << val  << '\n';
    return 0;
}


