#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ii pair<int,int>

vector<int> route;
vector <vector <int>> g;
int want;

bool dfs(int u){
    if(u == want){
        return true;
    }

    for(auto i:g[u]){
        if(dfs(i) == true){
            route.push_back(i);
            return true;
        }
    }

    return false;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("instruction.in", "r", stdin);
    freopen("instruction.out", "w", stdout);

    int n;
    cin >> n;

    g.resize(n+1);
    map <char, int> leg;

    int id =0;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        
        if(c == 's'){
            int x;
            cin >> x;

            g[x].push_back(i);
        }

        else{
            int s;
            char id;
            cin >> s >> id;
            leg[id] = i;

            g[s].push_back(i);
        }
    }


    int m;
    cin >> m;
    vector <ii> ans;
    vector <bool> state(n+1, 0);

    for(int i = 0; i < m; i++){
        int a;
        char dest;
        cin >> a >> dest;

        want = leg[dest];
        route = {};

        dfs(0);
        reverse(route.begin(), route.end());
        for(int j = 0; j <route.size() - 1; j++){
            if(g[route[j]][state[route[j]]] == route[j+1]) continue;

            state[route[j]] = !state[route[j]];
            ans.emplace_back(a + j + 1, route[j]);
        }
    }
    
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(auto [t, u]:ans){
        cout << u << " " << t << "\n";
    }
    
    return 0;
}