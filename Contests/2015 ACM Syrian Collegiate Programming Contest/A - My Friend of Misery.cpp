#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,char>> log;
        int min_cash = 0;
        for(int i = 0; i < n; i++){
            int val;
            char op;
            cin >> val >> op;
            log.emplace_back(val, op);
            if(op == '+'){
                min_cash += val + 25;
            }
        }
        int max_cash = INF;
        int answ = INF;
        for(int i = 0; i < n; i++){
            auto [val, op] = log[i];
            if(op == '+'){
                min_cash -= (val + 25);
            }
            else{
                max_cash = min(max_cash, val + 25);
                answ = min(answ, max_cash - min_cash);
            }
        }

        cout << answ << '\n';
    }
    return 0;
}