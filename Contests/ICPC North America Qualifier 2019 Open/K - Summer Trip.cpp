// 
#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;
const int MAXN = 1e5 + 100;
int segtree[4*MAXN];

void build(int p, int l, int r){
    if(l == r){
        segtree[p] = 0;
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc,l,m);
        build(rc,m+1,r);

        segtree[p] = segtree[lc] | segtree[rc];
    }
}

void update(int p, int l, int r, int idx){
    if(l == r){
        segtree[p] = segtree[p] | (1<<(s[idx] - 'a'));
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(idx <= m) update(lc,l,m,idx);
        else update(rc,m+1,r,idx);

        segtree[p] = segtree[lc] | segtree[rc];
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr){
        return (segtree[p]);
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) return query(lc,l,m,ql,qr);
        else if (ql > m) return query(rc,m+1,r,ql,qr);
        return query(lc,l,m,ql,qr) | query(rc,m+1,r,ql,qr);
    }
}

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string aux;
    cin >> aux;

    s = "*" + aux; //1-based;

    vector<int> idx_last(30,-1);
    int answ = 0;

    idx_last[s[1]-'a'] = 1;
    
    build(1,1,s.size());
    update(1,1,s.size(),1);

    for(int i = 2; i < s.size(); i++){
        if(idx_last[s[i]-'a'] == -1){
            int aux = query(1,1,s.size(),1,i);
            answ += __builtin_popcount(aux);
        }
        else{
            int aux = query(1,1,s.size(), idx_last[s[i]-'a']+1, i);
            answ += __builtin_popcount(aux);
        }
        update(1,1,s.size(),i);
        idx_last[s[i]-'a'] = i;
    }

    cout << answ << '\n';

    return 0;
}