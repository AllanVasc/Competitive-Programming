#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 4 * 1e4 + 5;
const int block = sqrt(ms);

struct Query{
    int l, r, idx;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
    bool operator < (Query &other){
        if(l / block != other.l / block) return (l / block) < (other.l / block);
        return (l / block & 1) ? (r < other.r) : (r > other.r);
    }
};

vector<Query> queries;
int v[ms], answ[ms];
int freq[ms];
int distinct = 0;
int seg[4 * ms];
void update(int p, int l, int r, int idx, int val){
    if(l == r){
        seg[p] += val;
    }
    else{
        int m = (l + r) >> 1;
        int lc = 2*p;
        int rc = lc + 1;
        if(idx <= m) update(lc, l, m, idx, val);
        else update(rc, m + 1, r, idx, val);
        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l, int r, int sum = 0){
    if(l == r) return l;
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(seg[rc] + sum >= m + 1){
        return query(rc, m + 1, r, sum);
    }
    else{
        return query(lc, l, m, sum + seg[rc]);
    }
    // if(qr <= m) return query(lc, l, m, ql, qr);
    // if(ql > m) return query(rc, m + 1, r, ql, qr);
    // return query(lc, l, m, ql, qr) + query(rc, m + 1, r, ql, qr);
}

void add(int x){
    if(freq[x] == 0) distinct++;
    int old = freq[x];
    update(1, 0, ms - 1, old, -1);
    freq[x]++;
    update(1, 0, ms - 1, old + 1, +1);
}

void remove(int x){
    if(freq[x] == 1) distinct--;
    int old = freq[x];
    update(1, 0, ms - 1, old, -1);
    freq[x]--;
    update(1, 0, ms - 1, old - 1, +1);
}

void Mo(){
    int curr_l = 0, curr_r = -1;
    sort(queries.begin(), queries.end());
    for(Query q : queries){
        while(curr_l > q.l){
            curr_l--;
            add(v[curr_l]);
        }
        while(curr_r < q.r){
            curr_r++;
            add(v[curr_r]);
        }
        while(curr_l < q.l){
            remove(v[curr_l]);
            curr_l++;
        }
        while(curr_r > q.r){
            remove(v[curr_r]);
            curr_r--;
        }
        // Precisa fazer aqui uma BB ??
        // int quality = 1;
        // int lo = 1;
        // int hi = distinct;
        // while(lo <= hi){
        //     int mid = (lo + hi) >> 1;
        //     int qtt = query(1, 0, ms - 1, mid, ms - 1);
        //     if(qtt >= mid){
        //         quality = max(quality, mid);
        //         lo = mid + 1;
        //     }
        //     else{
        //         hi = mid - 1;
        //     }
        // }
        int quality = query(1, 0, ms - 1);
        answ[q.idx] = quality;
    }
}

template<class T>
struct CoordinateCompression{
    vector<T> v;
    void push(const T & a) { v.push_back(a); }
    int build(){
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return (int) v.size();
    }
    int operator[] (const T & a){
        auto it = lower_bound(v.begin(), v.end(), a);
        return it - v.begin();
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; 
    cin >> n >> q;
    CoordinateCompression<int> cd;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cd.push(v[i]);
    }
    cd.build();
    for(int i = 0; i < n; i++){
        v[i] = cd[v[i]];
    }
    // Comprimi tudo ja!
    update(1, 0, ms - 1, 0, n); // Tenho n valores zerados
    for(int i = 0; i < q; i++){
        int l, r; 
        cin >> l >> r;
        l--, r--;
        queries.push_back(Query(l, r, i));
    }
    Mo();
    for(int i = 0; i < q; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}