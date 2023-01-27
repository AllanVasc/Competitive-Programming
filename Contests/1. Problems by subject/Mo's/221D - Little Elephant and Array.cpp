#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 1e5 + 5;
const int block = sqrt(MAXN);

struct Query{
    int l, r, idx;
    bool operator < (Query &other){
        if(l / block != other.l / block) return (l / block) < (other.l / block);
        return (l / block & 1) ? (r < other.r) : (r > other.r);
    }
};

vector<int> v;
vector<Query> queries;
int curr_answ = 0;
int freq[MAXN];

void add(int x){
    x = v[x];
    if(x >= MAXN) return;

    if(freq[x] == x) curr_answ--;
    freq[x]++;
    if(freq[x] == x) curr_answ++;
}

void remove(int x){
    x = v[x];
    if(x >= MAXN) return;

    if(freq[x] == x) curr_answ--;
    freq[x]--;
    if(freq[x] == x) curr_answ++;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < m; i++){
        Query q;
        cin >> q.l >> q.r;
        q.l--, q.r--;
        q.idx = i;
        queries.push_back(q);
    }
    sort(queries.begin(), queries.end());
    vector<int> answ(m, 0);
    int curr_l = 0, curr_r = -1;
    for(auto q : queries){
        while(curr_l > q.l){
            curr_l--;
            add(curr_l);
        }
        while(curr_r < q.r){
            curr_r++;
            add(curr_r);
        }
        while(curr_l < q.l){
            remove(curr_l);
            curr_l++;
        }
        while(curr_r > q.r){
            remove(curr_r);
            curr_r--;
        }
        answ[q.idx] = curr_answ;
    }

    for(int i = 0; i < m; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}