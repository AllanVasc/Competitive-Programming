// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> v; // Input
vector<vector<int>> v_copy; // Check

bool dfs(vector<vector<int>>& g, int u){

    for(auto vtx : g[u]){
        v_copy[u].push_back(vtx);
        if(!dfs(g, vtx)) return false;

        for(auto outrovertice : v_copy[vtx]){
            v_copy[u].push_back(outrovertice);
        }
    }
    sort(v_copy[u].begin(), v_copy[u].end());
    return v_copy[u] == v[u];
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    v.assign(n, vector<int>());
    v_copy.assign(n, vector<int>());

    int only_one = 0;
    int have_leaf = 0;

    for(int i = 0; i < n; i++){
        int qtd;
        cin >> qtd;

        if(qtd == n-1){
            only_one++;
        }
        if(qtd == 0){
            have_leaf++;
        }

        for(int j = 0; j < qtd; j++){
            int vtx;
            cin >> vtx;

            if(vtx-1 == i){
                cout << "NO" << '\n';
                return 0;
            }

            v[i].push_back(vtx-1);
        }
    }

    if(only_one != 1){
        cout << "NO" << '\n';
        return 0;
    }
    if(have_leaf == 0){
        cout << "NO" << '\n';
        return 0;
    }

    vector<int> ordem;
    for(int i = 0; i < n; i++){
        ordem.push_back(i);
    }

    sort(ordem.begin(), ordem.end(), [](int a, int b){
        return v[a].size() < v[b].size();
    });

    for(int i = 0; i < n; i++){
        sort(v[i].begin(), v[i].end());
    }

    vector<ii> answ;
    vector<vector<int>> g;
    g.assign(n, vector<int>());

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            auto itr = lower_bound(v[ordem[j]].begin(), v[ordem[j]].end(), ordem[i]);
            
            if(itr == v[ordem[j]].end()) continue;
            if(*itr != ordem[i]) continue;

            // cout << ordem[i]+1 << " achei em -> " << ordem[j]+ 1 << '\n';
            answ.push_back({ordem[j], ordem[i]});
            g[ordem[j]].push_back(ordem[i]);
            break;
        }
    }

    // Agora, meu grafo não pode ter Ciclo e nem componente desconexo.
    int root = ordem.back();

    if(!dfs(g, root)){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i].first + 1 << " " << answ[i].second + 1 << '\n';
        }
    }

    return 0;
}