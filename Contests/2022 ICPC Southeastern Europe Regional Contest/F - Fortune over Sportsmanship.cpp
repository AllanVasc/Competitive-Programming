#include <bits/stdc++.h>

using namespace std;
#define int long long

typedef pair <int, int> ii;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    vector <ii> ans;
    priority_queue <tuple <int, int, int>> pq;
    vector <bool> vis(n, 0);
    int missing = n-1;

    int mat[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
            if(i < j) pq.emplace(mat[i][j], i, j);
        }
    }

    while(missing){ //Passa no máximo n vezes
        int v, x, y;
        tie(v, x, y) = pq.top();
        pq.pop();

        if(vis[y] || vis[x] || x == y) continue;

        sum += v;
        missing--;
        ans.emplace_back(x+1, y+1);

        int win = min(x, y), lose = max(x, y);
        vis[lose] = true;

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            mat[i][win] = max(max(mat[i][x], mat[i][y]), max(mat[x][i], mat[y][i]));
            mat[win][i] = max(max(mat[i][x], mat[i][y]), max(mat[x][i], mat[y][i]));
            
            pq.emplace(mat[i][win], i, win);
        }
    }

    cout << sum << "\n";
    for(auto i:ans) cout << i.first << " " << i.second << "\n";

    return 0;
}