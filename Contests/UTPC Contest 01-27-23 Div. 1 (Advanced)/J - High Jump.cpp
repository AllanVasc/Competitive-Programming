#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

using namespace std;
using namespace __gnu_pbds;

// DO NOT USE #DEFINE INT LONG LONG IN CODE!
// If needed, initialize the multiset as long long normally
template<typename T>
class multi_indexed_set{

    tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag,
	    tree_order_statistics_node_update> miset;
    unordered_map<T, int> freq;

    public:
	void insert(T x){
	    freq[x]++;
	    miset.insert({x, freq[x]});
	}
	void erase(T x){
	    if(!freq[x]) return;
	    miset.erase({x, freq[x]});
	    freq[x]--;
	}
	int order_of_key(T x){ return miset.order_of_key({x, 0}); }
	int count(T x) { return freq[x]; }
	int size(){ return miset.size(); }

};

struct Node{
    int answ = -INF, first = 1, last = 1;
    Node(){
        answ = -INF;
        first = 1;
        last = 1;
    }
    Node(int x, int y, int z) : answ(x), first(y), last(z){}
};

const int ms = 1e5 + 100;
Node seg[4 * ms];
int lazy[4 * ms];

Node merge(Node l, Node r){
    Node result(-INF,0,0);
    result.first = l.first;
    result.last = r.last;
    result.answ = max({l.answ, r.answ, r.first - l.last});
    return result;
}

void build(int p, int l, int r){
    if(l == r){
        seg[p] = Node(-INF,1,1);
        lazy[p] = 0;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2 * p;
        int rc = lc + 1;

        build(lc, l, m);
        build(rc, m + 1, r);

        seg[p] = merge(seg[lc], seg[rc]);
    }
}

void propagate(int p, int l, int r){
    if(lazy[p] == 0) return;
    
    seg[p].first += lazy[p];
    seg[p].last += lazy[p];
    // cout << "\n";
    // cout << "propagate:" << '\n';
    // cout << "l = " << l << " r = " << r << '\n';
    // cout << "f = " << seg[p].first << " : l = " << seg[p].last << '\n';
    if(l != r){
        lazy[2 * p] += lazy[p];
        lazy[2*p + 1] += lazy[p];
    }
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int x){
    propagate(p, l, r);
    if(r < ql || l > qr) return;
    if(ql <= l && r <= qr){
        lazy[p] += x;
        propagate(p, l, r);
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2 * p;
        int rc = lc + 1;

        update(lc, l, m, ql ,qr, x);
        update(rc, m + 1, r, ql, qr, x);

        seg[p] = merge(seg[lc], seg[rc]);
    }
}

Node query(int p, int l, int r, int ql, int qr){
    propagate(p, l, r);
    if(ql <= l & r <= qr) return seg[p];

    int m = (l + r) >> 1;
    int lc = 2 * p;
    int rc = lc + 1; 

    if(qr <= m){
        return query(lc, l, m, ql, qr);
    }
    else if(ql > m) return query(rc, m + 1, r, ql, qr);

    return merge(query(lc, l, m, ql, qr), 
                 query(rc, m + 1, r, ql, qr));
}

void debug(int l,int r, int k){
    cout << l << " -> " << r << " = " << query(1,1,k,l,r).answ << '\n';
    cout << "h = " <<  query(1,1,k,l,r).first << " -> " << query(1,1,k,l,r).last << '\n'; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    multi_indexed_set<int> ms;
    build(1, 1, k);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ms.insert(x);
    }
    
    // cout << "antes: " << '\n';
    // for(int i = 1; i < k; i++){
    //     debug(i, i + 1, k);
    // }

    // update(1, 1, k, 2, 5, 2);

    // cout << "dps 1 up: " << '\n';
    // for(int i = 1; i < k; i++){
    //     debug(i, i + 1, k);
    // }
    // update(1, 1, k, 1, 1, 3);

    // cout << "dps 2 up: " << '\n';
    // for(int i = 1; i < k; i++){
    //     debug(i, i + 1, k);
    // }

    while(m--){
        int l, r, x;
        cin >> l >> r >> x;
        update(1, 1, k, l, r, x);
        
        Node result = query(1,1,k,1,k);
        // cout << "max de 1 pra 2: " << query(1,1,k,1,2).answ << '\n';
        // cout << "Max dif = " << result.answ << '\n';
        cout << ms.size() - ms.order_of_key(result.answ) << '\n';
    }

    return 0;
}