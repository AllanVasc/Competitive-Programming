#include <bits/stdc++.h>
#define int long long
#define iii tuple<int,int,int>
#define ii pair<int,int>

using namespace std;

const int ms = 2e5 + 10;
const int inf = 1e17 + 100;

iii seg[4*ms]; // max, min, soma dos vivos


void merge(int idx, int i, int j){
    auto [a, b, c] = seg[i];
    auto [x, y, z] = seg[j];
    seg[idx] = iii(max(a, x), min(y, b), c+z);
}

void build(vector<int> &v, int l, int r, int idx=0){
    if(l == r){
        seg[idx] = iii(v[l], v[l], 1);
        return;
    }
    int m = (l+r)/2;
    build(v, l, m, 2*idx +1), build(v, m+1, r, 2*idx +2);
    merge(idx, 2*idx +1, 2*idx +2);
}

void kill(int pos, int l, int r, int idx=0){
    if(l == r){
        seg[idx] = iii(-1, inf, 0);
        return;
    }

    int m = (l+r)/2;
    if(pos <= m) kill(pos, l, m, 2*idx +1);
    else kill(pos, m+1, r, 2*idx +2);
    merge(idx, 2*idx +1, 2*idx +2);
}

ii who(int id, int l, int r, int idx=0){ // id == 0, significa que to procurando o maximo
    if(l == r){
        return ii(l,(id == 0 ? get<0>(seg[idx]): get<1>(seg[idx])));
    }
    int m = (l+r)/2;
    int aux = (id == 0 ? get<0>(seg[idx]): get<1>(seg[idx]));
    auto [lx, li, y] = seg[2*idx +1];
    int sup = (id == 0 ? lx : li);
    if(sup == aux){
        return who(id, l, m, 2*idx +1);
    }
    return who(id, m+1, r, 2*idx +2);
}

int getSum(int L, int R, int l, int r, int idx=0){
    if(l > R || r < L) return 0;
    if(L <= l && r<= R) return get<2>(seg[idx]);
    int m = (l + r)/2;
    return getSum(L, R, l, m, 2*idx +1) + getSum(L, R, m+1, r, 2*idx +2);
}

void soma(int pos, int put, int l, int r, int idx =0){
    if(l == r){
        auto [a, b, c] = seg[idx];
        seg[idx] = iii(a +put, b+put, c);
        return;
    }
    int m = (l+r)/2;
    if(pos <=m){
        soma(pos, put, l, m, 2*idx +1);
    }
    else soma(pos, put, m+1, r, 2*idx +2);
    merge(idx, 2*idx +1, 2*idx +2);
}

int bbL(int id, int n, int put){
    int ans =-1;
    int l =0, r = id;
    while(l <= r){
        int m = (l+r)/2;
        int val = getSum(m, id, 0, n-1);
        if(val){
            ans = m;
            l = m+1;
        } 
        else r = m-1;
    }
    if(ans != -1) soma(ans, put, 0, n-1);
    return ans;
}
int bbR(int id, int n, int put){
    int ans = -1;
    int l=id, r = n-1;
    while(l <= r){
        int m = (l+r)/2;
        int val = getSum(id, m, 0, n-1);
        if(val){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    if(ans != -1) soma(ans, put, 0, n-1);
    return ans;
}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> v(n);
    int sum =0;

    for(int i=0; i<n; i++){
        cin >> v[i];
        sum += v[i];
    }
    build(v, 0, n-1);

    for(int i=0; i<n; i++){
        auto [idMax, maxi] = who(0, 0, n-1);
        auto [idMin, mini] = who(1, 0, n-1);
        if(maxi <= (sum - maxi)){ // nao ta em equilibrio
            cout << idMax+1 << " " << maxi << '\n';
            kill(idMax, 0, n-1);
            int put = maxi/2;
            int l = bbL(idMax, n, put);
            int r = bbR(idMax, n, put);
            if (l != -1) sum += put;
            if (r != -1) sum += put;

            sum -= maxi;
        }
        else{
            cout << idMin+1 << " " << mini << '\n';
            kill(idMin, 0, n-1);
            int put = mini/2;
            int l = bbL(idMin, n, put);
            int r = bbR(idMin, n, put);
            if(l != -1) sum += put;
            if(r != -1) sum += put;
            sum -= mini;
        }
    }
}







