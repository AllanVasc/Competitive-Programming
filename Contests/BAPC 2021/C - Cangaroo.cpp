// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 100 + 10;
const int MAXMASK = 1024 + 100;

int dp[MAXN][MAXMASK];
int n, m;
char matrix[100+10][10+10];

void clear(){
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j < MAXMASK; j++){
            dp[i][j] = -1;
        }
    }
}

bool isvalid(int mask, int prevmask, int row){

    //string str = bitset<4>(mask).to_string();
    //cout << "MASK ATUAL = " << str << '\n';
    //cout << "PREV MASK = " << bitset<10>(prevmask).to_string() << '\n';

    int qtdCans = __builtin_popcount(mask); // Par
    if(qtdCans%2 != 0) return false;

    // cout << "1. Tem 1's par" << '\n';

    // Mask Válida
    int count = 0;
    for(int i = 0; i < 10; i++){
        if(mask & 1<<i) count++;
        else{
            if(count%2 != 0) return false;
            else count = 0;
        }
    }

    if(count%2 != 0) return false;

    // cout << "1's seguidos são pares" << '\n';

    // mask ta em cima da outra mask
    count = 0;
    for(int i = 0; i < m; i++){
        if(mask & 1<<i) count++;
        if(count%2 == 1){
            if( ((prevmask & (1<<i)) == 0) && ((prevmask & (1<<(i+1))) == 0)) return false;
        }
    }

    // cout << "Mask em cima da outra" << '\n';

    // Mask cobre o canguru
    for(int i = 0; i < m; i++){
        if(matrix[row][i] == '#' || matrix[row-1][i] == '#'){
            if((mask & (1<<(m-i-1))) == 0) return false;
        }
    }

    // cout << "mask cobre o canguru" << '\n';

    return true;
}

int solve(int idx, int prevmask){

    if(idx < 0) return 0;
    if(dp[idx][prevmask] != -1) return dp[idx][prevmask];

    int answ = 30000;
    // cout << "LINHA = " << idx << '\n';
    for(int mask = 0; mask < (1<<m); mask++){
        // string str1 = bitset<4>(mask).to_string();
        // string str2 = bitset<4>(prevmask).to_string();
        // cout << "testando: mask = " << str1 << " prev mask = " << str2 << '\n';
        if(isvalid(mask, prevmask, idx)){
            // string str1 = bitset<4>(mask).to_string();
            // string str2 = bitset<4>(prevmask).to_string();
            // cout << "Deu valido: " << str1 << " prev mask = " << str2 << '\n';
            int cans = __builtin_popcount(mask)/2;
            // cout << "cans = " << cans << '\n';
            answ = min(answ, cans + solve(idx-2,mask));
        }
    }
    return dp[idx][prevmask] = answ;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    clear();
    int mask = (1<<m) - 1;
    cout << solve(n-1, mask) << '\n';
 
    return 0;
}
