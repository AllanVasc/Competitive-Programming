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

char v[3][3];
bool check(char c){
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        cnt = 0;
        for(int j = 0; j < 3; j++){
            if(v[i][j] == c) cnt++;
        }
        if(cnt == 3) return true;
    }
    cnt = 0;
    for(int i = 0; i < 3; i++){
        cnt = 0;
        for(int j = 0; j < 3; j++){
            if(v[j][i] == c) cnt++;
        }
        if(cnt == 3) return true;
    }

    cnt = 0;
    for(int i = 0; i < 3; i++){
        if(v[i][i] == c) cnt++;
    }
    if(cnt == 3) return true;
    cnt = 0;
    for(int i = 0; i < 3; i++){
        if(v[i][2 - i] == c) cnt++;
    }
    if(cnt == 3) return true;
    
    return false;
}

signed main() {
    optimize;
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cin >> v[i][j];
            }
        }

        if(check('X')){
            cout << 'X' << '\n';
        }
        else if(check('O')){
            cout << 'O' << '\n';
        }
        else if(check('+')){
            cout << '+' << '\n';
        }
        else cout << "DRAW" << '\n';
    }
    return 0;
}