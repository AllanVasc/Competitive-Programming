// C - Brexit 
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

const int N = 2e5 + 5;
vector<int> adj[N];

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int c,p,x,l;
    cin >> c >> p >> x >> l;

    set<ii> freq;

    map<int,int> total;
    map<int,int> out;

    for(int i = 0; i < p; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        total[u]++;
        total[v]++;
    }

    stack<int> leave;
    leave.push(l);

    vector<int> leaved(N, 0);

    while(leave.empty() == false && leaved[x] == 0){

        int i = leave.top();
        leave.pop();

        leaved[i] = 1;

        for(int j = 0; j < adj[i].size(); j++){

            out[adj[i][j]]++;
            if(out[adj[i][j]] >= total[adj[i][j]]/2.0 && leaved[adj[i][j]] == 0){
                leave.push(adj[i][j]);
            }
        }
    }

    if(leaved[x] == 0) cout << "stay" << '\n';
    else cout << "leave" << '\n';

    return 0;
}
