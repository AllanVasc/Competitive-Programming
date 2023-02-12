#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;

const int MAXN = 50000 + 50;

vector<int> g[MAXN];
bool is_prime[MAXN];
vector<int> primes;
int parent[MAXN], sz[MAXN], removed[MAXN], height[MAXN];
int freq[MAXN];
int answ;

// Preprocessing subtree sizes
void dfsSubtree(int u, int p){
    sz[u] = 1;
    for(auto v : g[u]){
        if(v != p && !removed[v]){
            dfsSubtree(v, u);
            sz[u] += sz[v];
        }
    }
}

// For each subtree we find its centroid
int getCentroid(int u, int p, int curr_size){
    for(auto v : g[u]){
        if(v != p && !removed[v] && sz[v] * 2 >= curr_size){
            return getCentroid(v, u, curr_size);
        }
    }
    return u;
}

void dfsCount(int u, int p, int depth, int & max_depth, int flag){
    max_depth = max(max_depth, depth);

    if(flag){
        for(auto prime : primes){
            if(prime - depth > max_depth) break;
            if(prime - depth >= 0) answ += freq[prime - depth];
        }
    }
    else freq[depth]++;

    for(auto v : g[u]){
        if(!removed[v] && v != p){
            dfsCount(v, u, depth + 1, max_depth, flag);
        }
    }
}

void solve(int u, int p){
    int max_depth = 0;
    freq[0] = 1;
    for(auto v : g[u]){
        if(!removed[v] && v != p){
            dfsCount(v, u, 1, max_depth, true);
            dfsCount(v, u, 1, max_depth, false);
        }
    }
    for(int i = 0; i <= max_depth; i++) freq[i] = 0;
}

// Algorithm to perform Centroid Decomposition
void decompose(int u, int p = -1, int lvl = 0){
    dfsSubtree(u, -1);
    int ctr = getCentroid(u, -1, sz[u]);
    parent[ctr] = p;
    height[ctr] = lvl;  // Assigning a level to the centroid

    solve(ctr, -1);
    removed[ctr] = 1;
    for(auto v : g[ctr]){
        if(v != p && !removed[v]){
            decompose(v, ctr, lvl + 1);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < MAXN; i++){
        if(is_prime[i]){
            for(int j = i * i; j < MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }

    for(int i = 0; i < MAXN; i++){
        if(is_prime[i]) primes.push_back(i);
    }
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    decompose(0);
    int total = n * (n - 1) / 2;
    long double output = (long double) answ / (long double) total;
    cout << fixed << setprecision(8);
    cout << output << '\n';
    return 0;
}