// J - SUM and REPLACE 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const ll INF = 1e9 + 7;

vector<int> v;
const int MAX = 3*1e5 + 10;
ii segTree[4*MAX];

vector<int> divs(1000000 + 10, 0);

void build(int p, int l, int r){

    if(l == r){
        if(v[l] == 1 || v[l] == 2){
            segTree[p] = {v[l], 1};
        }
        else{
            segTree[p] = {v[l], 0};
        }
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(lc,l,m);
        build(rc,m+1,r);

        if(segTree[lc].second && segTree[rc].second) 
            segTree[p] = {segTree[lc].first + segTree[rc].first, 1};
        else
            segTree[p] = {segTree[lc].first + segTree[rc].first, 0};
    }
}

ii query(int p, int l, int r, int ql, int qr){

    if(ql <= l && r <= qr){
        return segTree[p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m){
            return query(lc, l , m, ql, qr);
        }
        else if(ql > m){
            return query(rc,m+1,r,ql,qr);
        }
        else{
            ii left = query(lc, l, m, ql,qr);
            ii right = query(rc, m+1, r,ql, qr);

            if(left.second && right.second)
                return {left.first + right.first, 1};
            else
                return {left.first + right.first, 0};
        }
    }
}

void update(int p, int l, int r, int ql, int qr){

    if(segTree[p].second == 1) return;

    if(l == r){
        segTree[p].first = divs[segTree[p].first];
        segTree[p].second = segTree[p].first <= 2;
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m){
            update(lc, l, m, ql, qr);
        }
        else if(ql > m){
            update(rc, m+1, r, ql, qr);
        }
        else{
            update(lc,l,m,ql,qr);
            update(rc,m+1,r,ql,qr);
        }

        if(segTree[lc].second && segTree[rc].second) 
            segTree[p] = {segTree[lc].first + segTree[rc].first, 1};
        else
            segTree[p] = {segTree[lc].first + segTree[rc].first, 0};
    }
}

// int countDivisors(int n){
//     int answ = 0;
//     for(int i = 1; i*i <= n; i++){
//         if(n%i == 0){
//             int x = i;
//             int y = n/i;
//             if(x != y) answ += 2;
//             else answ++;
//         }
//     }
//     return answ;
// }

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < 1000000 + 10; i++)
        for (int j = i; j < 1000000 + 10; j += i)
            divs[j]++;
    
    int n,m;

    cin >> n >> m;

    v.push_back(-1);
    for(int i = 0; i < n; i ++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }

    build(1,1, v.size()-1);

    for(int i = 0; i < m; i++){
        int op, f, s;
        cin >> op >> f >> s;
        if(op == 1){       
            update(1,1,v.size()-1, f,s);
        }
        else{
            cout << query(1,1,v.size()-1,f,s).first << '\n';
        }
    }

    return 0;
}