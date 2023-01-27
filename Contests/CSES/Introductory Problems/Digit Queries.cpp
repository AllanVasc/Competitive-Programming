#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int fexp(int x,int y){
    int answ = 1;
    while(y){
        if(y & 1) answ *= x;
        x *= x;
        y >>= 1;
    }
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    const int ms = 18;

    vector<int> qtd_numbers(ms, 0);
    int count = 0;
    int less = 0;
    for(int i = 1; i < ms; i++){
        count *= 10;
        count += 9;
        if(i == 1) less = 0;
        if(i == 2) less = 1;
        less *= 10;
        if(i == 1) qtd_numbers[i] = count - less;
        else qtd_numbers[i] = count - less + 1;
    }

    vector<int> qtddigits(ms, 0);
    for(int i = 1; i < ms; i++){
        qtddigits[i] = qtddigits[i - 1] + i * qtd_numbers[i];
        // cout << qtddigits[i] << '\n';
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int k;
        cin >> k;

        // cout << "k = " << k << '\n';
        int pos = lower_bound(qtddigits.begin(), qtddigits.end(), k) - qtddigits.begin();
        // cout << "meu numero tem: " << pos << " digitos\n";

        k -= qtddigits[pos - 1];
        int number = fexp(10, pos - 1) + ((k - 1)/ pos);
        string s = to_string(number);
        // cout << "number = " << s << '\n';
        
        // cout << "k = " << k << '\n';
        k = (k - 1) % pos;
        // cout << "k = " << k << '\n';
        
        cout << s[k] << '\n';

    }
    return 0;
}