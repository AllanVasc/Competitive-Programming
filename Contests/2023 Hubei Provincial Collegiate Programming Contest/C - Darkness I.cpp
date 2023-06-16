#include <bits/stdc++.h>
 
using namespace std;
                                 
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define int long long
#define endl '\n'


void solve(){ 
    int n, m;
    cin >> n >> m;
    if(n > m)swap(n, m);

    int ans = n;
    ans += (m - n)/2 + ((m - n)%2);
    cout << ans << endl;
}
 
  
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}