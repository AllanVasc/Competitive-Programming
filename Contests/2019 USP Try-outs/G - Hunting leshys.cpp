#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;

int parent[MAXN];
int sie[MAXN];
int answ[MAXN];

vector<int> powers;

void build(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        sie[i] = 1;
        answ[i] = powers[i];
    }
}

int Find(int v){
    if(v == parent[v]) return v;
    int paiV = parent[v];
    parent[v] = Find(parent[v]);
    answ[v] = min(answ[v],answ[paiV]);
    return parent[v];
}

void Union(int a, int b){
    int antA = a;
    a = Find(a);
    b = Find(b);

    if(a != b){
        parent[b] = a;
        answ[b] = min(answ[antA], answ[b]);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    powers.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> powers[i];

    build(n);

    while(m--){

        char command;
        cin >> command;

        if(command == '?'){
            int q;
            cin >> q;
            int atu = Find(q-1);
            cout << answ[q-1] << '\n';
        }
        else{
            int x, y;
            cin >> x >> y;
            Union(x-1,y-1);
        }
    }

    return 0;
}