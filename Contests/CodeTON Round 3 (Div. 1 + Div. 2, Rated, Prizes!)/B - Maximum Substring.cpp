#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int max_qtd_a = 0, max_qtd_b = 0;
        int answ = 0;

        int count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                count++;
                if(max_qtd_a < count) max_qtd_a = count;
            }
            else{
                count = 0;
            }
        }

        answ = max(answ, max_qtd_a*max_qtd_a);

        count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                count++;
                if(max_qtd_b < count) max_qtd_b = count;
            }
            else{
                count = 0;
            }
        }

        answ = max(answ, max_qtd_b*max_qtd_b);

        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') a++;
            else b++;
        }

        answ = max(answ, a*b);

        cout << answ << '\n';

    }
    return 0;
}