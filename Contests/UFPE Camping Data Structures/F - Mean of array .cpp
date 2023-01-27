//  F - Mean of array 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 200000 + 100;

vector<int> seg;
vector<int> v;

void update(int p, int l, int r, int idx, int value){
    if(l == r){
        seg[p] += value;
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(idx <= m) update(lc,l,m,idx,value);
        else update(rc,m+1,r,idx,value);

        seg[p] = seg[lc] + seg[rc];
    }
}

int query(int p, int l,int r, int ql,int qr){
    if(l >= ql && r <= qr){
        return seg[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) return query(lc,l,m,ql,qr);
        else if(ql > m) return query(rc,m+1,r,ql,qr);
        else return query(lc,l,m,ql,qr) + query(rc,m+1,r,ql,qr);
    }
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;

    v.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] -= k;
    }

    // Debug
    // cout << "V - K: ";
    // for(int i = 1; i <= n; i++){
    //     cout << v[i] << " ";
    // } cout << '\n';

    vector<int> prefixsum;

    prefixsum.assign(n+1, 0);

    set<int> compress;

    compress.insert(0);

    for(int i = 1; i <= n; i++){
        prefixsum[i] = prefixsum[i-1] + v[i];
        compress.insert(prefixsum[i]);
    } 

    // Debug
    // cout << "PREFIX SUM: ";
    // for(int i = 1; i <= n; i++){
    //     cout << prefixsum[i] << " ";
    // } cout << '\n';

    map<int,int> mapping;
    
    int count = 0;
    // cout << "COMPRESS: ";
    for(auto i: compress){
        mapping[i] = count + 1;
        count++; 
        // cout << mapping[i] << " ";
    } // cout << '\n';

    seg.assign(4*MAXN, 0);
    update(1,1,count, mapping[0], 1);

    int answ = 0;
    for(int i = 1; i <= n; i++){
        answ += query(1,1,count, 1, mapping[prefixsum[i]]);
        // cout << "Dando update no idx = " << mapping[prefixsum[i]] << '\n';
        update(1,1,count, mapping[prefixsum[i]],1);
        
    }

    // cout << "SEG: ";
    // for(int i = 1; i <= count; i++){
    //     cout << query(1,1,count,i,i) << " ";
    // } cout << '\n';

    cout << answ << '\n';

    return 0;
}
