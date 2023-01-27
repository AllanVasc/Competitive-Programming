//  A - Who is the winner?
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18; 
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--){
 
        int h1,m1,s1,h2,m2,s2;
        cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
 
        int victory = 0;
 
        int player1 = h1*3600 + m1*60 + s1;
        int player2 = h2*3600 + m2*60 + s2;
 
        if(player1 < player2){
            cout << "Player1" << '\n';
        }
        else if(player2 < player1){
            cout << "Player2" << '\n';
        }
        else cout << "Tie" << '\n';
    }
    return 0;
}
