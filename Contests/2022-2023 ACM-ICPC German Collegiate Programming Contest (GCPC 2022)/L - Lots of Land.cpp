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

vector<vector<char>> answ;
void paint(int l, int w, int n, int s1, int s2){
    answ.assign(l, vector<char>(w, '*'));
    char curr = 'A';
    for(int i = 0; i < l; i += s1){
        for(int j = 0; j < w; j += s2){
            for(int k = i; k < i + s1; k++){
                for(int z = j; z < j + s2; z++){
                    answ[k][z] = curr;
                }
            }
            curr++;
        }
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < w; j++){
            cout << answ[i][j]; 
        }
        cout << '\n';
    }
}

int32_t main() {
    optimize;
    
    int l, w, n;
    cin >> l >> w >> n;
    if(l * w % n != 0){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        int area1 = l * w / n;

        bool found = false;
        for(int i = 1; i <= area1 && !found; i++){
            if(area1 % i != 0) continue;
            int side2 = area1 / i;
            // cout << "i = " << i << " side2 = " << side2 << '\n';
            if(l % i != 0 || w % side2 != 0) continue;
            int qtt = 0;
            qtt += (l / i) * (w / side2);
            // cout << "qtt = " << qtt << '\n';
            if(qtt == n){
                paint(l, w, n, i, side2);
                found = true;
            }
        }
        if(!found) cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}