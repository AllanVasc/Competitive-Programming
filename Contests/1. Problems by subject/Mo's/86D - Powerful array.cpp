#include <bits/stdc++.h>
using namespace std;

#define int int64_t

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXN = 200000 + 10;
const int block = sqrt(MAXN);

// Ordering based on the Hilbert curve
inline int64_t hilbertOrder(int x, int y, int pow, int rotate){
    if(pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3) : ( (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query{
    int l, r, idx;
    int64_t ord;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {
        ord = hilbertOrder(l, r, 21, 0);
    }
    bool operator < (Query &other){
        return ord < other.ord;
    }
};

vector<int> v;
vector<Query> queries;
int curr_answ = 0;
int freq[(int)1e6 + 10];

void add(int x){
    x = v[x];
    curr_answ -= freq[x] * freq[x] * x;
    freq[x]++;
    curr_answ += freq[x] * freq[x] * x;
}

void remove(int x){
    x = v[x];
    curr_answ -= freq[x] * freq[x] * x;
    freq[x]--;
    curr_answ += freq[x] * freq[x] * x;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, t;
    cin >> n >> t;
    v.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < t; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        Query q(l, r, i);
        queries.push_back(q);
    }

    sort(queries.begin(), queries.end());
    vector<int> answ(t, 0);
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

    for(int i = 0; i < t; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}