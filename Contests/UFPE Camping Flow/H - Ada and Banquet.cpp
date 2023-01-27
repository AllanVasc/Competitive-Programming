//  H - Ada and Banquet
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

vector<vector<int>> g;

int stoer_wagner(int n){
    int answ = LONG_LONG_MAX;
    for(int i = 1; i < n; i++){   // Need to repeat only n-1 times
        vector<int> weight(n, 0);
        vector<bool> visited(n, false);

        int prev = -1, v = 0, cnt = 1, current_cut = 0;
        while(cnt <= n-i){ // Creating the subset until only 1 node is missing
            visited[v] = true;
            int nxt = -1;
            current_cut = 0;

            for(int j = 0; j < n; j++){ // Looking for edge with the greatest weight connected to current subset
                weight[j] += g[v][j];
                if(!visited[j] && weight[j] > current_cut){
                    nxt = j;
                    current_cut = weight[j];
                }
            }

            cnt++;
            prev = v;
            v = nxt;
        } // At the end of the loop "v" is the disconnected node and "prev" was the last node that reached it

        answ = min(answ, current_cut);
        for(int j = 0; j < n; j++){ // Joining the last 2 nodes, putting the edges of "v" in "prev"
            if(j != prev){
                g[j][prev] += g[j][v];
                g[prev][j] += g[v][j];
            }
            g[j][v] = 0; // Emptying the weights to "v" because "v" will no longer exist
        }
    }
    return answ;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    for(int i = 0; i < n; i++) g[i].resize(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    cout << 2*stoer_wagner(n) << '\n';

    return 0;
}
