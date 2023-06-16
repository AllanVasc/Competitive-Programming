#include <bits/stdc++.h>
using namespace std;


#define int long long

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        map<string, int> mp;
        int ans=0;
        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            set<string> st;
            for(int j=0; j<s.size(); j++){
                string tome;
                for(int k=j; k<s.size(); k++){
                    tome.push_back(s[k]);
                    st.insert(tome);
                }
            }

            for(auto x : st){
                int aux = mp[x]++;
                if(aux) ans = max(ans,(int)x.size());
            }
        }
        cout << ans << '\n';

        
    }

    return 0;
}
