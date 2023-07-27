#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s, t;
    cin >> s >> t;

    vector<vector<int> > v(27);
    for(int i=0; i<s.size(); i++) v[s[i] - 'a'].push_back(i);

    int ans =1;
    int id=0;
    for(int i=0; i<t.size(); i++){
        int c = t[i] - 'a';
        auto it = lower_bound(v[c].begin(), v[c].end(), id);
        if(it == v[c].end()){
            ans++;
            id = v[c][0] + 1;
        }
        else{
            id = *it + 1;
        }
    }

    cout << ans << endl;


}


