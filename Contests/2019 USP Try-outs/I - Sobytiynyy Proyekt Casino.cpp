#include <bits/stdc++.h>
using namespace std;
 
#define int long long
typedef pair<int,int> pii;
 
vector<pii> deli;
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        deli.push_back({b,a});
    }
    
    sort(deli.begin(),deli.end());
    int tenho = 0;
    int ans = -10000000000;
    for(int i=0; i<n; i++){
        tenho += deli[i].second;
        int res = tenho - deli[i].first;
        ans = max(res,ans);
    }
    cout << ans << endl;   
    return 0;
}