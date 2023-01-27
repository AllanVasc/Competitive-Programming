// M - French Raisins Gym
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int N = 18; // Number of elements

vector<vector<double>> prob;
double dp[1<<N][N];

void build(){

    for(int i = 0; i < (1<<18); i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = -1;
        }
    }
}

int n;

double solve(int idxWin, int mask){

    if(dp[mask][idxWin] != -1) return dp[mask][idxWin];

    int alive = __builtin_popcount(mask);

    if(alive == 1) return 1;

    double round_prob = 1 / ((alive * (alive-1))/2.0);
    double answ = 0;

    for(int i = 0; i < n; i++){
        if(((1<<i)&(mask)) == 0) continue;
        for(int j = i+1; j < n; j++){
            if(((1<<j)&(mask)) == 0) continue;

            else if(i == idxWin){
                mask = mask^(1<<j);
                answ += round_prob * prob[i][j] * solve(idxWin, mask);
                mask = mask^(1<<j);
            }
            else if(j == idxWin){
                mask = mask^(1<<i);
                answ += round_prob * prob[j][i] * solve(idxWin, mask);
                mask = mask^(1<<i);
            }
            else{
                mask = mask^(1<<j);
                answ += round_prob * prob[i][j] * solve(idxWin, mask);
                mask = mask^(1<<j);

                mask = mask^(1<<i);
                answ += round_prob * prob[j][i] * solve(idxWin, mask);
                mask = mask^(1<<i);
            }
        }
    }

    return dp[mask][idxWin] = answ;
}


int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    prob.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            double aux;
            cin >> aux;
            prob[i].push_back(aux);
        }
    }

    build();

    int mask = (1<<n)-1;

    cout << fixed << setprecision(10);

    for(int i = 0; i < n; i++){
        cout << solve(i, mask) << '\n';
    }

    return 0;
}
