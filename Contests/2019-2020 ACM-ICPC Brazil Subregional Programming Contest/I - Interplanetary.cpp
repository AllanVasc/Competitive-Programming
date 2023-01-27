// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

void printg(vector<vector<int>>& g){
    cout << "graph:" << '\n';
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g.size(); j++){
            cout << g[i][j] << " ";
        }
        cout << '\n';
    }
}

void solve(vector<vector<int>> g, vector<ii> temperatures, priority_queue<tuple<int,int,int,int>>& pq, vector<int>& answ){
    int n = g.size();
    
    int count = 0;
    for(int k = 0; k < n; k++){
        int curr_v = temperatures[k].second;
        int curr_temp = temperatures[k].first;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                g[i][j] = min(g[i][j], g[i][curr_v] + g[curr_v][j]);
            }
        }

        if(k < n-1 && curr_temp == temperatures[k+1].first) continue; // Tenho temperaturas iguais, logo não faço query agr
        count++;

        while(!pq.empty()){

            auto aux = pq.top();
            int qtd = abs(get<0>(aux));

            if(count >= qtd){
                pq.pop();
                int u,v,idx;
                
                u = get<1>(aux);
                v = get<2>(aux);
                idx = get<3>(aux);

                // cout << "processando: " << u << " -> " << v << " idx =  " << idx << '\n';

                if(g[u][v] != INF) answ[idx] = g[u][v];
            }
            else{
                break;
            }
        }
    }

    while(!pq.empty()){

        auto aux = pq.top();
        int qtd = abs(get<0>(aux));

        pq.pop();
        int u,v,idx;
        
        u = get<1>(aux);
        v = get<2>(aux);
        idx = get<3>(aux);

        // cout << "processando: " << u << " -> " << v << " idx =  " << idx << '\n';

        if(g[u][v] != INF) answ[idx] = g[u][v];
    }
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,r;
    cin >> n >> r;

    vector<vector<int>> g;
    g.assign(n, vector<int>(n, INF));
    
    vector<ii> temperatures;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        temperatures.push_back({temp,i});
    }

    for(int i = 0; i < r; i++){
        int x, y, d;
        cin >> x >> y >> d;
        g[x-1][y-1] = d;
        g[y-1][x-1] = d;
    }

    for(int i = 0; i < n; i++) g[i][i] = 0;
    // printg(g);

    int q;
    cin >> q;
    priority_queue<tuple<int,int,int,int>> pq_cold; // k,u,v,i
    priority_queue<tuple<int,int,int,int>> pq_hot; // k,u,v,i
    
    for(int i = 0; i < q; i++){
        int a, b, k, t;
        cin >> a >> b >> k >> t;
        if(t == 0){ // mais frio
            pq_cold.push({-k,a-1,b-1,i});
        }
        else{ // mais quente
            pq_hot.push({-k,a-1,b-1,i});
        }
    }

    vector<int> answ;
    answ.assign(q, -1);

    sort(temperatures.begin(), temperatures.end());
    // cout << "temp = ";
    // for(int i = 0; i < n; i++) cout << temperatures[i].first << " ";
    // cout << '\n';

    solve(g, temperatures, pq_cold, answ);
    
    reverse(temperatures.begin(), temperatures.end());
    // cout << "temp = ";
    // for(int i = 0; i < n; i++) cout << temperatures[i].first << " ";
    // cout << '\n';

    solve(g, temperatures, pq_hot, answ);

    for(int i = 0; i < q; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}