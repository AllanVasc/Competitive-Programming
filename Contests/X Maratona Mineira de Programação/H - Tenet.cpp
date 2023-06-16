#include <bits/stdc++.h>

using namespace std;
#define int long long



int32_t main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    string s;
    cin >> s;
    set<char> st;

    for(int i=0; i<s.size(); i++) st.insert(s[i]);

    vector<int> ord;
    for(char x : st)ord.push_back(x - 'a');
    sort(ord.begin(), ord.end());

    int ans=0;
    vector<int> cnt(1 << 21, 0);
    cnt[0] =1;
    int xr = 0;
    for(int i=0; i<s.size(); i++){
        int tome = lower_bound(ord.begin(), ord.end(), s[i] - 'a') - ord.begin();
        xr ^= (1 << tome);
        ans += cnt[xr];
        for(int j=0; j<20; j++){
            int alvo = (1 << j) ^xr;
            ans += cnt[alvo]; 
        }
        cnt[xr]++;
    }
    cout << ans << endl;
}

