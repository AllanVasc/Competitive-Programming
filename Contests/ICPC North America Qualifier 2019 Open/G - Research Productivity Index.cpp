// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int MAXN = 100 + 10;
long double dp[MAXN][MAXN][MAXN];
vector<long double> v;

void clear(){
    for(int i = 0; i < MAXN ; i++)
        for(int j = 0; j < MAXN; j++)
            for(int k = 0; k < MAXN; k++)
                dp[i][j][k] = -1;
}

long double solve(int idx, int ac, int total){
    if(idx >= total){
        if(ac == 0) return 0;
        else return pow(ac,ac/(double)total);
    }
    if(dp[idx][ac][total] != -1) return dp[idx][ac][total];

    long double p1 = v[idx];
    long double p2 = 1 - p1;

    long double answ = p1*solve(idx+1,ac+1,total) + p2*solve(idx+1,ac,total);

    return dp[idx][ac][total] = answ;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    v.assign(n,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        v[i] /= 100.0;
    }
    sort(v.begin(), v.end(), greater<long double>());
    clear();

    long double answ = 0;
    for(int i = 1; i <= n; i++){
        answ = max(answ, solve(0,0,i));
    }
    
    cout << fixed << setprecision(8);
    cout << answ << '\n';
    return 0;
}
