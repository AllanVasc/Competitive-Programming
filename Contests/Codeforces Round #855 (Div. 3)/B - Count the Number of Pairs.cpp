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

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> flower(30, 0), fupper(30, 0);
        for(int i = 0; i < n; i++){
            if(islower(s[i])){
                flower[s[i] - 'a']++;
            }
            else{
                fupper[s[i] - 'A']++;
            }
        }
        int answ = 0;
        for(int i = 0; i < 30; i++){
            int qtd1 = flower[i];
            int qtd2 = fupper[i];
            if(qtd1 > qtd2) swap(qtd1, qtd2);

            int matched = min(qtd1,qtd2);
            answ += matched;
            qtd1 -= matched;
            qtd2 -= matched;
            
            int canTurn = qtd2 / 2;
            int swaps = min(k, canTurn);
            k -= swaps;
            answ += swaps;
        }
        cout << answ << '\n';
    }
    return 0;
}