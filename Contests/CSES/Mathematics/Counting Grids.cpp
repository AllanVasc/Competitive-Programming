#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexpo(int x, int y){
    x = x%MOD;
    int answ = 1;
    while(y){
        if(y & 1) answ = answ*x % MOD;
        x = x*x%MOD;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    // Burnside's lemma: https://www.youtube.com/watch?v=D0d9bYZ_qDY
    int n;
    cin >> n;

    int expdegree0 = n * n;
    int expdegree90 = 1;
    int expdegree180 = 1;
    int expdegree270;
    int qtdColor = 2;
    int qtdRotation = 4;

    if(n == 1){
        cout << 2 << '\n';
        return 0;
    }
    else if(n % 2 == 0){
        expdegree90 = n*n / 4;
        expdegree180 = n*n / 2;
    }
    else{
        expdegree90 = (n/2 + 1)*(n/2 + 1) - (n/2);
        expdegree180 = (n/2)*n + (n/2 + 1);
    }
    expdegree270 = expdegree90;

    int answ = 0;
    answ = (answ + fexpo(qtdColor, expdegree0)) % MOD;
    answ = (answ + fexpo(qtdColor, expdegree90)) % MOD;
    answ = (answ + fexpo(qtdColor, expdegree180)) % MOD;
    answ = (answ + fexpo(qtdColor, expdegree270)) % MOD;

    answ = (answ * fexpo(qtdRotation, MOD - 2)) % MOD;
    cout << answ << '\n';

    return 0;
}