#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

signed main() {
    optimize;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> filas(k + 1);
    vector<int> pointer(k + 1, 0);
    vector<int> tin(n + 1, 0);
    queue<int> events;
    vector<int> answ;
    for(int i = 0; i < 2*n; i++){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int pi, fi; cin >> pi >> fi;
            events.push(pi);
            filas[fi].push_back(pi);
            tin[pi] = i;
        }
        else{
            int fi; cin >> fi;
            int currPi = filas[fi][pointer[fi]++];
            // cout << "vai sair " << currPi << '\n';
            while(!events.empty()){
                auto pf = events.front();
                if(tin[pf] > tin[currPi]){
                    break;
                }
                else if(tin[pf] < tin[currPi]){
                    answ.push_back(pf);
                    events.pop();
                }
                else{
                    events.pop();
                    break;
                }
            }
        }
    }
    sort(answ.begin(), answ.end());
    cout << answ.size() << '\n';
    for(auto x : answ) cout << x << " ";
    cout << '\n';
    return 0;
}