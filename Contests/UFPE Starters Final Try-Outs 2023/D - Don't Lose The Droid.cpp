#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

bool check(int r, int c, int n, int m){
    return r >= 0 && r < n && c >= 0 && c < m;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m, t;
    cin >> n >> m >> t;

    int maxD = 0;
    int maxE = 0;
    int maxC = 0;
    int maxB = 0;
    int offsetR = 0;
    int offsetC = 0;
    for(int i = 0; i < t; i++){
        char curr;
        cin >> curr;
        if(curr == 'D'){
            offsetC++;
            if(offsetC >= 0){
                maxD = max(maxD, offsetC);
            }
            else{
                maxE = min(maxE, offsetC);
            }
        }
        else if(curr == 'E'){
            offsetC--;
            if(offsetC >= 0){
                maxD = max(maxD, offsetC);
            }
            else{
                maxE = min(maxE, offsetC);
            }
        }
        else if(curr == 'B'){
            offsetR++;
            if(offsetR >= 0){
                maxB = max(maxB, offsetR);
            }
            else{
                maxC = min(maxC, offsetR);
            }
        }
        else if(curr == 'C'){
            offsetR--;
            if(offsetR >= 0){
                maxB = max(maxB, offsetR);
            }
            else{
                maxC = min(maxC, offsetR);
            }
        }
    }
    // cout << "offset row = " << offsetR << " offset coloumn = " << offsetC << '\n';
    // cout << maxB << " " << maxC << '\n';
    // cout << maxE << " " << maxD << '\n';
    int answ = 0;
    vector<ii> pos;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(check(i + maxC, j + maxE, n, m) &&
               check(i + maxB, j + maxD, n, m)){
                answ++;
                pos.push_back({i + offsetR, j + offsetC});
               }
        }
    }
    cout << answ << '\n';
    for(auto [r,c] : pos){
        cout << (n - r) << " " << c + 1 << '\n';
    }
    return 0;
}