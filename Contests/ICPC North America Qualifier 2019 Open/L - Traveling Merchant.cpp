// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 1e5 + 100;

struct Node{
    int min = 1e18;
    int max = -1e18;
    int answ = 0;
};

Node segtree[7][4*MAXN];
Node rv_segtree[7][4*MAXN];

int table[7][MAXN];
int rv_table[7][MAXN];

Node combine(const Node& l, const Node& r){
    Node aux;

    aux.answ = max(l.answ, r.answ);
    aux.answ = max(aux.answ, r.max - l.min);
    aux.min = min(l.min, r.min);
    aux.max = max(l.max, r.max);

    return aux;
}

void build(int day, int p, int l, int r){
    if(l == r){
        segtree[day][p].answ = 0;
        segtree[day][p].min = table[day][l];
        segtree[day][p].max = table[day][l];
        
        rv_segtree[day][p].answ = 0;
        rv_segtree[day][p].min = rv_table[day][l];
        rv_segtree[day][p].max = rv_table[day][l];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        build(day, lc, l, m);
        build(day, rc, m+1, r);

        segtree[day][p] = combine(segtree[day][lc], segtree[day][rc]);
        rv_segtree[day][p] = combine(rv_segtree[day][lc], rv_segtree[day][rc]);

        // cout << l << " para " << r << " : ";
        // cout << segtree[day][p].max << " " << segtree[day][p].min << " " << segtree[day][p].answ << '\n'; 
    }
}

Node query(int day, int p, int l, int r, int ql, int qr, bool rev){
    if(l >= ql && r <= qr){
        if(rev) return rv_segtree[day][p];
        else return segtree[day][p];
    }
    else{
        int m = (l+r)/2;
        int lc = 2*p;
        int rc = lc + 1;

        if(qr <= m) return query(day, lc, l, m, ql, qr, rev);
        else if(ql > m) return query(day, rc, m+1, r, ql, qr, rev);
        
        return combine(query(day, lc, l, m, ql, qr, rev), query(day, rc, m+1, r, ql, qr, rev));
    }
}

void debug(int n){

    cout << "NORMAL TABLE: " << '\n';
    for(int i = 0; i < 7; i++){
        cout << "DIA " << i << " :" << " ";
        for(int j = 1; j <= n; j++){
            cout << table[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';

    cout << "REVERSE TABLE: " << '\n';
    for(int i = 0; i < 7; i++){
        cout << "DIA " << i << " :" << " ";
        for(int j = 1; j <= n; j++){
            cout << rv_table[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    vector<int> d;
    for(int i = 0; i < n; i++){
        int vi, di;
        cin >> vi >> di;
        v.push_back(vi);
        d.push_back(di);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 7; j++){
            int ii = i + j;

            if(ii % 7 == 0 || ii % 7 == 6){
                table[j][i+1] = v[i];
            }
            else if(ii % 7 == 1 || ii % 7 == 5){
                table[j][i+1] = v[i] + d[i];
            }
            else if(ii % 7 == 2 || ii % 7 == 4){
                table[j][i+1] = v[i] + 2*d[i];
            }
            else{
                table[j][i+1] = v[i] + 3*d[i];
            }
        }
    }

    reverse(v.begin(), v.end());
    reverse(d.begin(), d.end());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 7; j++){
            int ii = i + j;

            if(ii % 7 == 0 || ii % 7 == 6){
                rv_table[j][i+1] = v[i];
            }
            else if(ii % 7 == 1 || ii % 7 == 5){
                rv_table[j][i+1] = v[i] + d[i];
            }
            else if(ii % 7 == 2 || ii % 7 == 4){
                rv_table[j][i+1] = v[i] + 2*d[i];
            }
            else{
                rv_table[j][i+1] = v[i] + 3*d[i];
            }
        }
    }

    // debug(n);

    for(int i = 0; i < 7; i++)
        build(i, 1, 1, n);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int s,t;
        cin >> s >> t;

        bool rev = false;
        if(s > t){
            rev = true;
            s = n - s + 1;
            t = n - t + 1;
        }

        int day = (7 - (s-1)%7)%7;
        // cout << "day = " << day << '\n';

        Node aux = query(day, 1, 1, n, s, t, rev);
        // cout << "Relatorio: " << '\n';
        // cout << "Max = " << aux.max << '\n';
        // cout << "Min = " << aux.min << '\n';
        // cout << "Answ = ";
        cout << aux.answ<< '\n';
    }
    return 0;
}
