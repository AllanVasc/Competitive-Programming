#include <bits/stdc++.h>
 
using namespace std;
                                 
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define int long long
#define endl '\n'

int x, y;
const int MAXN = 1e6 + 5;

void solve(){
    cin >> x >> y;

    if(y % 100 != 0){
        cout << -1 << endl;
        return;
    }

    y /= 100;
    int ansa = -1;
    int ansb = -1;
    int ansc = -1;
    for(int i = 0; i < MAXN; ++i){
         int  cc= y - 10*i;
         if(cc % 25 == 0 && cc >= 0 && x - i - cc/25 >= 0){
            ansc = cc/25;
            ansb = i;
            ansa = x - ansb - ansc;
         }
    }

    if(ansa == -1){
        cout << -1 << endl;
        return;
    }

    cout << ansa << " " << ansb << " " << ansc << endl;
    return;
}
 
  
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}