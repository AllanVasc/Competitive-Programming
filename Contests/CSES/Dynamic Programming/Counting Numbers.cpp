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

int dp[20][11][3];
int solve(int idx, int last, int limited, string & s){
    int n = s.size();
    if(idx >= n) return 1;
    int & answ = dp[idx][last][limited];
    if(answ != -1) return answ;
    answ = 0;
    if(limited){
        int digit = s[idx] - '0';
        for(int i = 0; i <= digit; i++){
            if(i == last) continue;
            answ += solve(idx + 1, i, i == digit, s);
        }
    }
    else{
        for(int i = 0; i < 10; i++){
            if(i == last) continue;
            answ += solve(idx + 1, i, false, s);
        }
    }
    return answ;
}

signed main() {
    optimize;
    int a, b;
    cin >> a >> b;
    string s = to_string(b);
    string aux;

    int answ = 0;
    while(aux.size() + 1 != s.size()){
        memset(dp, -1, sizeof dp);
        aux.push_back('9');
        answ += solve(0, 0, true, aux);
    }
    memset(dp, -1, sizeof dp);
    answ += solve(0, 0, true, s);
    answ++; // Faltou o 0

    if(a){
        aux.clear();
        a--;
        s = to_string(a);
        while(aux.size() + 1 != s.size()){
            memset(dp, -1, sizeof dp);
            aux.push_back('9');
            answ -= solve(0, 0, true, aux);
        }
        memset(dp, -1, sizeof dp);
        answ -= solve(0, 0, true, s);
        answ--; // Faltou o 0
    }
    cout << answ << '\n';
    return 0;
}