#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 200 * 50 * 2;
const int sigma = 26;
int trie[ms][sigma], terminal[ms], points[ms];
int z = 1;

void add(string & s, int score){
    int curr = 0;
    for(int i = 0; i < s.size(); i++){
        int id = s[i] - 'a';
        if(!trie[curr][id]) trie[curr][id] = z++;
        curr = trie[curr][id];
    }
    points[curr] = max(points[curr], score);
    terminal[curr] = true;
}
const int mxSz = 50;
int dp[mxSz][mxSz][ms];
string text;

// dp[l][r][v] = melhor ganho pegando TODA string [l, r] e minha ultima string que eu estava pegando
// corresponde ao prefix de "v" na trie.
int solve(int l, int r, int v){
    if(l > r){
        if(v){
            return terminal[v] ? points[v] : -INF;
        }
        return 0;
    } 
    int & answ = dp[l][r][v];
    if(answ != -INF) return answ;

    if(terminal[v]){
        answ = max(answ, points[v] + solve(l, r, 0));
    }

    for(int i = l; i <= r; i++){
        int id = text[i] - 'a';
        if(!trie[v][id]) continue;
        answ = max(answ, solve(l, i - 1, 0) + solve(i + 1, r, trie[v][id]));
    }
    return answ;
}

// dp2[l][r] = melhor resposta escolhendo um prefix [l, l'] para ser totalmente resolvido
// pela dp1 + dp2[l' + 1, r] ou ignoro text[l] e vou para dp2[l + 1, r]
int dp2[mxSz][mxSz]; 
int solve2(int l, int r){
    if(l > r) return 0;
    int & answ = dp2[l][r];
    if(answ != -INF) return answ;
    answ = max(answ, solve2(l + 1, r));
    for(int i = l; i <= r; i++){
        answ = max(answ, solve(l, i, 0) + solve2(i + 1, r));
    }
    return answ;
}

signed main() {
    optimize;

    cin >> text;

    int qtt; cin >> qtt;
    for(int i = 0; i < qtt; i++){
        string s; cin >> s;
        int score; cin >> score;
        add(s, score);
        reverse(ALL(s));
        add(s, score);
    }
    for(int i = 0; i < mxSz; i++){
        for(int j = 0; j < mxSz; j++){
            dp2[i][j] = -INF;
            for(int k = 0; k < ms; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    // cout << solve2(0, text.size() - 1) << '\n';

    vector<int> dp3(text.size() + 1, 0);
    for(int i = 1; i <= text.size(); i++){
        for(int j = 0; j < i; j++){
            dp3[i] = max(dp3[i], dp3[j] + max(0LL, solve(j, i - 1, 0)));
        }
    }
    cout << dp3[text.size()] << '\n';
    return 0;
}