#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> tamanho;

void build(int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        tamanho[i] = 1;
    }
}

int Find(int v){
    if(v == parent[v]) return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b){
    // cout << "pai de " << a << " = " << Find(a) << '\n';
    // cout << "pai de " << b << " = " << Find(b) << '\n';
    a = Find(a);
    b = Find(b);
    if(a != b){
        if(tamanho[a] < tamanho[b]) swap(a,b);
        parent[b] = a;
        tamanho[a] += tamanho[b];
        // cout << tamanho[a] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        map<string,int> mp;
        int n;
        cin >> n;
        int count = 0;
        parent.assign(3*n, 0);
        tamanho.assign(3*n, 0);
        build(3*n);

        for(int i = 0; i < n; i++){

            string b1, b2;
            cin >> b1 >> b2;

            if(mp.find(b1) == mp.end()){
                mp[b1] = count;
                count++;
            }
            if(mp.find(b2) == mp.end()){
                mp[b2] = count;
                count++;
            }

            Union(mp[b1], mp[b2]);

            cout << max(tamanho[Find(mp[b1])], tamanho[Find(mp[b2])]) << '\n';
        }
    }
    return 0;
}