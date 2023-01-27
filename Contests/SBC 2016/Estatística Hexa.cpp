// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int sum[1<<16];
string v[70];

struct Node{
    int min;
    int max;
    int sum;
    Node(int sum = -1, int min = 0, int max = 0): sum(sum), min(min), max(max){}
};

Node dp[(1<<16) + 1];
int fat[17];

Node solve(int mask){
    int removed = __builtin_popcount(mask);

    if(removed == 16){
        return Node(0, 0, 0);
    }

    Node &answ = dp[mask];

    if(answ.sum != -1) return answ;

    answ = Node(0, 0x3f3f3f3f3f3f3f3f, 0);

    int qtd = removed + 1;
    int f = fat[16 - qtd];

    for(int i = 0; i < 16; i++){
        if (mask & (1<<i)) continue;

        int check = mask ^ (1<<i);
        int s = sum[check];

        Node aux = solve(check);

        answ.min = min(answ.min, s + aux.min);
        answ.max = max(answ.max, s + aux.max);

        answ.sum = (answ.sum + s % MOD*f%MOD + aux.sum) % MOD;
    }
    return answ;
}

// int minimo(int mask){

//     if(__builtin_popcount(mask) == 16){
//         return 0;
//     }

//     if(dp[mask] != -1) return dp[mask];

//     int answ = LONG_LONG_MAX;

//     for(int i = 0; i < 16; i++){
//         if((mask & (1<<i)) == 0){
//             int check = mask | (1<<i);
//             answ = min(answ, sum[check] + minimo(check));
//         }
//     }
//     return dp[mask] = answ;
// }

// int maximo(int mask){

//     if(__builtin_popcount(mask) == 16){
//         return 0;
//     }

//     if(dp[mask] != -1) return dp[mask];

//     int answ = 0;

//     for(int i = 0; i < 16; i++){
//         if((mask & (1<<i)) == 0){
//             int check = mask | (1<<i);
//             answ = max(answ, sum[check] + maximo(check));
//         }
//     }
//     return dp[mask] = answ;
// }

// int soma(int mask){

//     if(__builtin_popcount(mask) == 16){
//         return 0;
//     }

//     if(dp[mask] != -1) return dp[mask];

//     int answ = 0;

//     for(int i = 0; i < 16; i++){
//         if((mask & (1<<i)) == 0){
//             int check = mask | (1<<i);
//             int qtd = __builtin_popcount(check);
//             answ = (answ + (sum[check]%MOD*fat[16 - qtd]%MOD + soma(check))%MOD)%MOD;
//         }
//     }
//     return dp[mask] = answ;
// }

inline int getId (char c) {
    if (isdigit(c)) return c-'0';
    return c - 'a' + 10;
}

// void preprocess(int mask){

//     // set<char> remove;
//     // for(int i = 0; i < 16; i++){
//     //     if(mask & (1 << i)){
//     //         remove.insert(dict[i]);
//     //     }
//     // }

//     for(auto &s : v){
        
//         int value = 0;
//         for(int i = 0; i < s.size(); i++){
//             if((mask & (1 << getDigit(s[i]))) == 0) value = 16*value + getDigit(s[i]);
//         }

//         //istringstream iss(aux);
//         //iss >> hex >> value;
//         sum[mask] += value;
//     }
// }

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> hex >> n;

    fat[0] = 1;
    for(int i = 1; i < 17; i++){
        fat[i] = fat[i-1] * i % MOD;
    }

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int i = 0; i < (1<<16); i++) {
        for (int j = 0; j < n; j++) {
        int x = 0;
        for (auto &c: v[j]) {
            if (i & (1<<getId(c))) continue;
            x = (x*16 + getId(c));
        }
        sum[i] += x;
        }
    }

    // memset(dp, -1, sizeof(dp));
    // int min_answ = minimo(0);

    // memset(dp, -1, sizeof(dp));
    // int max_answ = maximo(0);

    // memset(dp, -1, sizeof(dp));
    // int sum_answ = soma(0);

    Node answ = solve(0);
    cout << hex << answ.min << " " << answ.max << " " << answ.sum << '\n';
    return 0;
}