#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MDICE = 15, MTYPE = 7, MSUM = 600;
long double dp[MDICE][MTYPE][MSUM];
int amount[5], dices[5] = {4, 6, 8, 12, 20};

int32_t main(){
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < 5; i++) cin >> amount[i];

    dp[0][0][0] = 1;
    for(int type = 0; type < 5; type++){
        for(int dice = 0; dice < amount[type]; dice++){
            for(int sum = 0; sum <= 500; sum++){
                for(int val = 1; val<=dices[type]; val++){
                    if(dice + 1 == amount[type]){
                        dp[0][type+1][sum + val] += dp[dice][type][sum];
                    }
                    
                    else
                        dp[dice+1][type][sum + val] += dp[dice][type][sum];
                }
            }
        }

        if(amount[type] == 0){
            for(int sum = 0; sum <= 500; sum++){
                dp[0][type+1][sum] += dp[0][type][sum];
            }
        }
    }

    vector <pair <long double, int>> ans;
    for(int i = 0; i < MSUM; i++){
        if(dp[0][5][i]) ans.emplace_back(dp[0][5][i], i);
    }

    sort(ans.rbegin(), ans.rend());
    for(auto i:ans) cout << i.second << " ";

    return 0;
}