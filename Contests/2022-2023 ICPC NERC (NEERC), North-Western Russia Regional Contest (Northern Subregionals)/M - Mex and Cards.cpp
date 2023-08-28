#include<bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e12;
const int ms = 1e6;
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
        seg[p] = min(seg[lc], seg[rc]);
    }
}

int query(int p, int l, int r, int ql, int qr){
    if(l >= ql && r <= qr) return seg[p];
    int m = (l + r) >> 1;
    int lc = 2*p;
    int rc = lc + 1;
    if(qr <= m) return query(lc, l, m, ql, qr);
    else if(ql > m) return query(rc, m + 1, r, ql, qr);
    else return min(query(lc, l, m, ql, qr), query(rc, m + 1, r, ql, qr));
}

// achar o menor MEX dessa fila
int bb(int ai, vector<int> & freq){
    int fila = freq[ai];
    int l = 0;
    int r = ms - 1;
    int answ = r;
    while(l <= r){
        int m = (l + r) >> 1;
        int mn = query(1, 0, ms - 1, 0, m); // min de freq[0.. m]
        if(mn < freq[ai]){
            // Existe um valor menor
            answ = min(answ, m);
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return answ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    vector<int> freq(ms, 0);
    for(int i = 0; i < n; i++){
        cin >> freq[i];
        update(1, 0, ms - 1, i, freq[i]);
    }
    
    // preciso saber a resposta inicial
    int answ = 0;
    int oldVal = INF;
    for(int i = 0; i < n; i++){
        int val = freq[i];
        // cout << "val de " << i << " = " << val << '\n';
        val = min(val, oldVal);
        answ += val;
        oldVal = val;
    }
    cout << answ << '\n';

    int q; cin >> q;
    while(q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int x; cin >> x;
            // vou botar x
            update(1, 0, ms - 1, x, 1);
            freq[x]++;
            int newMex = bb(x, freq);
            if(newMex < x){ // nao vai mudar
                //continue;
            }
            else{
                answ += (newMex - x);
            }
        }
        else{
            int x; cin >> x;
            // vou tirar x
            int oldMex = bb(x, freq);
            if(oldMex < x){
                //continue;
                // nao vai mudar a resposta
            }
            else{
                answ -= (oldMex - x);
            }
            update(1, 0, ms - 1, x, -1);
            freq[x]--;
        }
        cout << answ << '\n';
    }
    return 0;
}