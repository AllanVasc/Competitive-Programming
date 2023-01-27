// A - YES or YES?
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
        string s;
        cin >> s;
        for(int i = 0; i < 3; i++)
            s[i] = tolower(s[i]);
        if(s == "yes") cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
 
    return 0;
}