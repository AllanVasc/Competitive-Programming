#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<ii>> g;
vector<vector<tuple<int,int,int>>> new_edges;

vector<int> dist, diameter;
vector<int> answ;

void precalc(int u, int parent){
    int bestdia1 = 0;
    int bestdia2 = 0;

    for(auto [v, w] : g[u]){
        if(v == parent) continue;
        precalc(v, u);
        dist[u] = max(dist[u], w + dist[v]);
        int curr = w + dist[v];
        if(bestdia1 < curr) swap(bestdia1, curr);
        if(bestdia2 < curr) swap(bestdia2, curr);
        diameter[u] = max(diameter[u], diameter[v]);
    }
    diameter[u] = max(diameter[u],  bestdia1 + bestdia2);
}

// Minha resposta passa pela nova aresta modificada
void dfs1(int u, int parent, int parentDist){
    vector<ii> bestDist;
    for(auto [v, w] : g[u]){
        if(v == parent) continue;
        bestDist.push_back({w + dist[v], v});
    }
    sort(bestDist.begin(), bestDist.end(), greater<ii>());

    for(auto [v, w, i] : new_edges[u]){
        if(v == parent) continue;
        int answ_base = parentDist;

        for(auto [currDist, brother] : bestDist){
            if(brother == v) continue;
            answ_base = max(answ_base, currDist);
            break;
        }

        answ[i] = max(answ[i], answ_base + w + dist[v]);
    }

    for(auto [v, w] : g[u]){
        if(v == parent) continue;
        int answ_base = parentDist;

        for(auto [currDist, brother] : bestDist){
            if(brother == v) continue;
            answ_base = max(answ_base, currDist);
            break;
        }

        dfs1(v, u, answ_base + w);
    }
}

// minha melhor resposta não é passando pela aresta atual
map<ii,int> answEdges;
void dfs2(int u, int parent, int parentDist, int parentDiam){
    vector<ii> bestDist;
    vector<ii> bestDia;
    for(auto [v, w] : g[u]){
        if(v == parent) continue;
        bestDist.push_back({w + dist[v], v});
        bestDia.push_back({diameter[v], v});
    }
    sort(bestDist.begin(), bestDist.end(), greater<ii>());
    sort(bestDia.begin(), bestDia.end(), greater<ii>());
    
    for(auto [v, w] : g[u]){
        if(v == parent) continue;

        // Minha resposta base é algum diametro melhor do meu pai
        int answ_base = parentDiam;
        
        // Vendo se a minha resposta é na vdd algum diametro do meu brother
        for(auto [diaBrother, brother] : bestDia){
            if(v == brother) continue;
            answ_base = max(answ_base, diaBrother);
            break;
        }

        // Vendo se a minha melhor resposta é na vdd a distancia subindo + algum irmão
        for(auto [distBrother, brother] : bestDist){
            if(v == brother) continue;
            answ_base = max(answ_base, parentDist + distBrother);
            break;
        }

        // Vendo se a minha resposta é a combinação de dist de 2 irmãos
        int bestDistBrother1 = 0;
        int bestDistBrother2 = 0;
        for(auto [distBrother, brother] : bestDist){
            if(v == brother) continue;
            if(bestDistBrother1 < distBrother) swap(bestDistBrother1, distBrother);
            if(bestDistBrother2 < distBrother) swap(bestDistBrother2, distBrother);
            if(bestDistBrother2 != 0) break;
        }

        if(bestDistBrother2 != 0)
            answ_base = max(answ_base, bestDistBrother1 + bestDistBrother2);

        // Melhor resposta sem pegar a nova aresta w pode ser:
        // 1ª - O diametro do meu filho "v", sem passar pelo w
        // 2º - Eu passando de um dist brother para o outro dist brother
        // 3º - Algum diametro acima (parentDia) 
        // 4º - Diametro de algum brother.
        ii key = minmax({u, v});
        answEdges[key] = max(answEdges[key], max(diameter[v], answ_base));

        int passBestDist = max(bestDistBrother1, parentDist);
        dfs2(v, u, passBestDist + w, answ_base);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    g.assign(n, vector<ii>());
    new_edges.assign(n, vector<tuple<int,int,int>>());
    dist.assign(n, 0);
    diameter.assign(n, 0);

    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int query;
    cin >> query;
    vector<ii> changes;
    changes.assign(query, {0,0});
    for(int i = 0; i < query; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        new_edges[u].push_back({v, w, i});
        new_edges[v].push_back({u, w, i});
        ii key = minmax(u,v);
        changes[i] = minmax({u, v});
    }

    answ.assign(query, 0);

    precalc(0, 0);
    dfs1(0, 0, 0);
    dfs2(0, 0, 0, 0);
    for(int i = 0; i < query; i++){
        cout << max(answ[i], answEdges[changes[i]]) << '\n';
    }

    return 0;
}