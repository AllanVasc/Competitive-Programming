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
    
    int t;
    cin >> t;
    while(t--){
        int n, m, h;
        cin >> n >> m >> h;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        priority_queue<pii> pq;
        pii rudolf;
        for(int i = 0; i < n; i++){
            sort(ALL(v[i]));
            int points = 0;
            int penalty = 0;
            int time = 0;
            for(int j = 0; j < m; j++){
                if(time + v[i][j] > h) break;
                points++;
                time += v[i][j];
                penalty += time;
            }
            if(i == 0){
                rudolf = {points, -penalty};
            }
            pq.push({points, -penalty});
        }
        int rank = 1;
        while(!pq.empty()){
            pii aux = pq.top();
            pq.pop();
            if(aux == rudolf) break;
            rank++;
        }
        cout << rank << '\n';
    }
    return 0;
}