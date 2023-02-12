#include <bits/stdc++.h>
using namespace std;
  
// #define int long long    -> MLE

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 10;
// const int BLOCK = sqrt(MAXN); -> MLE
const int BLOCK = 150;
// As vezes se torna interessante reduzir o BLOCK para evitar cache miss tambem.

struct Node{
    int parent;
    int next;
};

// Function used to initialize Disjoint Set
void Build(vector<Node>& v, vector<int>& sizes, int jump){
    for(int i = 0; i < MAXN; i++){
        v[i].parent = i;
        v[i].next = min(i + jump, MAXN);
        sizes[i] = 1;
    }
}

// Returns the representative of the set that contains the element "v" (Path Compression Optimization)
Node Find(vector<Node>& v, int idx) {
    if(idx == v[idx].parent)
        return v[idx];
    return v[idx] = Find(v, v[idx].parent);
}

// Joins two different sets (Union by Size Optimization)
void Union(vector<Node>& v, vector<int>& sizes, int idx_a, int idx_b) {
    Node a = Find(v, idx_a);
    Node b = Find(v, idx_b);
    if (a.parent != b.parent) {
        // We put the smallest set in the largest
        if (sizes[a.parent] < sizes[b.parent]) swap(a, b);

        v[b.parent].parent = a.parent;
        sizes[a.parent] += sizes[b.parent];
        v[a.parent].next = max(a.next, b.next);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<tuple<int,int,int,char>> queries;
    for(int i = 0; i < q; i++){
        int start, a, k;
        char c;
        cin >> start >> a >> k >> c;
        queries.push_back({start - 1, a, k, c});
    }
    reverse(queries.begin(), queries.end());

    string answ;
    int n = s.size();
    for(int i = 0; i < n; i++){
        answ.push_back('?');
    }

    // Building DSU to A <= sqrt(N)
    vector<vector<Node>> dsu(BLOCK + 5, vector<Node>(MAXN));
    vector<vector<int>> szs(BLOCK + 5, vector<int>(MAXN, 0));
    for(int i = 1; i <= BLOCK; i++){
        Build(dsu[i], szs[i], i);
    }

    // Running Queries
    for(int i = 0; i < q; i++){
        auto [idx, a, k, curr_c] = queries[i];

        int last_idx = idx + k * a;

        // Brute force O(q * sqrt(N) )
        if(a >= BLOCK){
            for(int j = idx; j < n && j <= last_idx; j += a){
                if(answ[j] == '?'){
                    answ[j] = curr_c;
                }
            }
        }
        else{ // a < sqrt(N) Sqrt Decomposition

            vector<Node>& curr_dsu = dsu[a];
            vector<int>& curr_szs = szs[a];
            int curr_idx = idx;
            int last_component = idx;
            while(curr_idx < n && curr_idx <= last_idx){
                if(answ[curr_idx] == '?'){
                    answ[curr_idx] = curr_c;
                }
                Union(curr_dsu, curr_szs, curr_idx, last_component);
                last_component = curr_idx;
                curr_idx = curr_dsu[curr_idx].next;
            }

        }
    }

    for(int i = 0; i < n; i++){
        if(answ[i] == '?') answ[i] = s[i];
    }
    cout << answ << '\n';
    return 0;
}