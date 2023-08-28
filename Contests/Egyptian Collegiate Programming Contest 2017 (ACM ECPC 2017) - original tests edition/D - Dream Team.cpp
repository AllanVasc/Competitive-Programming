#include <bits/stdc++.h>

using namespace std;

const int ms = 1e5 + 100;
int par[ms], sz[ms];
int comp;
void build(){
    for(int i = 0; i < ms; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int u){ return u == par[u] ? u : par[u] = find(par[u]); }
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    comp--;
}

int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    freopen("dream.in", "r", stdin); // NAO ESQUECER
    int t; cin >> t;

    for(int cs = 1; cs <= t; cs++){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<vector<int>> idxs(ms);
        for(int i = 0; i < n; i++){
            for(int j = 1; j * j <= v[i]; j++){
                if(v[i] % j == 0){
                    idxs[j].push_back(i);
                    if(v[i] / j != j) idxs[v[i] / j].push_back(i);
                }
            }
        }
        build();
        comp = n;
        long long answ = 0;
        for(int i = ms - 1; i >= 0 && comp != 1; i--){
            for(int j = 1; j < idxs[i].size(); j++){
                int idx1 = idxs[i][j - 1];
                int idx2 = idxs[i][j];
                if(find(idx1) != find(idx2)){
                    answ += i;
                    merge(idx1, idx2);
                }
            }
        }
        cout << "Case " << cs << ": " << answ << '\n';
    }
    return 0;
}