// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> triangles;
    triangles.assign(n, vector<int>());

    for(int i = 0; i < n; i++){
        int x, y;
        for(int j = 0; j < 3; j++){
            cin >> x >> y;
            triangles[i].push_back(y);
        }

        sort(triangles[i].begin(), triangles[i].end() );
    }

    vector<tuple<int,int,int>> sweep; // Altura, começa/termina, vertice;
    for(int i = 0; i < n; i++){
        sweep.push_back({triangles[i][0], 1, i});
        sweep.push_back({triangles[i][2], 2, i});
    } 

    sort(sweep.begin(), sweep.end());

    int answ = 0;
    int curr = 0;

    for(int i = 0; i < sweep.size(); i++){
        auto aux = sweep[i];
        int y = get<0>(aux);
        int command = get<1>(aux);
        
        if(command == 1){
            curr++;
        }
        else{
            curr--;
        }

        answ = max(answ, curr);
    }

    cout << answ << '\n';

    return 0;
}