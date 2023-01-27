//  G - The jar of divisors
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
        int n;
        cin >> n;

        if(n > 1) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }

    return 0;
}
