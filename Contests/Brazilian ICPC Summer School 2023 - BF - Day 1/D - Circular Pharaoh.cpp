#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    string s;
    cin >> s;
    vector<int> div;
    int n = s.size();
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            div.push_back(i);
            if(n / i != i) div.push_back(n/i);
        }
    }

    // cout << "divisores = ";
    // for(auto x : div) cout << x << " ";
    // cout << '\n';

    int answ = 0;
    for(auto val : div){
        bool canBe = true;
        for(int i = 0; i < n / val; i++){
            for(int j = 0; j < val; j++){
                if(s[j] != s[i*val + j]) canBe = false;
            }
        }

        if(canBe){
            // cout << "deu bom com " << val << '\n';
            if(val != n) answ += (n / val) * val;
            else answ++;
        }
    }
    cout << answ << '\n';

    return 0;
}