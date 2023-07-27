#include <bits/stdc++.h>
 
using namespace std;
                                 
#define pb push_back
#define ll long long
#define ii pair<int, int>
#define iii tuple<int, int, int>
#define endl '\n'

int n;
vector<int> v;
vector<int> color;

void solve(){ 
    cin >> n;
    v.resize(2*n + 2);
    color.resize(2*n + 2, -1);
    for(int i = 0; i < 2*n + 2; ++i){
        cin >> v[i];
    }

    vector <bool> ans(n, 0);
    for(int i = 1; i < n; i++){
        if(v[2*i + 1] == 1){
            ans[i] = !ans[i-1];
        }
        else ans[i] = ans[i-1];
    }  

    for(auto i:ans) cout << (i ? 'b':'a');
    cout << "\n";  
}
 
  
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}