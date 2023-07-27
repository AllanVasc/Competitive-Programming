#include<bits/stdc++.h>

using namespace std; 

const int ms = 1e6 + 100;
const int sigma = 26;
int trie[ms][sigma];
int terminal[ms];
int z = 1;
void insert(string & s, int x){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(trie[curr][id] == 0){
            trie[curr][id] = z++;
        }
        curr = trie[curr][id];
    }
    terminal[curr] += x;
}
long long answ = 0;

void dfs(int v, long long cnt){
    cnt += terminal[v];
    answ = max(answ, cnt);
    for(int i = 0; i < sigma; i++){
        if(trie[v][i] != 0){
            dfs(trie[v][i], cnt);
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int x; cin >> x;
        insert(s, x);
    }
    dfs(0, 0);
    cout << answ << '\n';
    return 0;
}