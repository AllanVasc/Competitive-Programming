#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <vector <int>> dp;
vector <vector <pair <int, int>>> shoes;

int solve(int pos, int amount, int n, int t){
    if(pos == n || amount < 0) return 0;
    int &ans = dp[pos][amount];
    // cout << pos << " " << amount << " " << n << " " << t << endl;
    if(~ans) return ans;

    ans = solve(pos+1, amount, n, t);
    if(amount - shoes[t][pos].first >= 0) ans = max(ans, solve(pos+1, 
                                                amount -  shoes[t][pos].first, n, t) +  shoes[t][pos].second);
    return ans;
}


int32_t main(){
    int n, t;
    cin >> n >> t;

    shoes.resize(t);
    for(int i = 0; i < n; i++){
        int k, sz, m;
        cin >> k >> sz >> m;

        sz--;
        shoes[sz].emplace_back(k/2, m);
    }

    vector <int> qtd(t);
    for(int i = 0; i < t; i++){
        int e, d;
        cin >> e >> d;
        qtd[i] = min(e, d);
    }

    int ans = 0;
    for(int i = 0; i < t; i++){
        dp.assign(shoes[i].size(), vector <int> (qtd[i] + 1, -1));
        ans += solve(0, qtd[i], shoes[i].size(), i);
    }

    cout << ans << "\n";

}