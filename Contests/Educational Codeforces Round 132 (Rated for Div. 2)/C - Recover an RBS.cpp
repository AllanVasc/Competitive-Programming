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
        string s;
        cin >> s;
        int n = s.size();

        int cur_op = 0, cur_close = 0;
        for(auto x : s){
            if(x == '(') cur_op++;
            if(x == ')') cur_close++;
        }

        int need_op = n/2 - cur_op;
        int need_close = n/2 - cur_close;

        if(need_op == 0 || need_close == 0){
            cout << "YES" << "\n";
            continue;
        }
        
        string check = string(need_op - 1, '(') + string(1, ')') + string(1, '(') + string(need_close - 1, ')');
        bool has_answ = true;
        int ptr = 0;
        int cnt = 0;
        for(auto x : s){
            if(x == '('){
                cnt++;
            }
            else if(x == ')'){
                cnt--;
            }
            else if(x == '?'){
                if(check[ptr] == '(') cnt++;
                else cnt--;
                ptr++;
            }

            if(cnt < 0) has_answ = false;
        }

        if(has_answ) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}