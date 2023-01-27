// K - Kilo Waste
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int MAXN = 60000;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int k, p;
    cin >> k >> p;

    vector<int> rice;

    rice.resize(p);
    for(int i = 0; i < p; i++){
        cin >> rice[i];
    }

    vector<bool> can_buy;

    can_buy.resize(MAXN + 5);
    int last_idx = 0;

    can_buy[0] = true;
    for(int i = 0; i < MAXN - 500; i++){

        if(can_buy[i]){
            for(int j = 0; j < p; j++){
                can_buy[i + rice[j]] = true;
                if(i + rice[j] > last_idx) last_idx = i + rice[j];
            }
        }
    }

    vector<int> dp;
    dp.resize(MAXN + 5);

    for(int i = last_idx; i >= 0; i--){

        if(can_buy[i] == true){
            dp[i] = i;
            last_idx = i;
        }
        else{
            dp[i] = last_idx;
        }
    }

    for(int i = 0; i < k; i++){
        int day;
        cin >> day;

        cout << dp[day] - day << '\n';
    }


    return 0;
}
