#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int answ = 0;
        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            set<char> st;
            int most = 0;
            for(int j = i; j < n && (j - i) < 100; j++){
                st.insert(s[j]);
                freq[s[j] - '0']++;
                most = max(most, freq[s[j] - '0']);
                if(most <= st.size()) answ++;
            }   
        }

        cout << answ << '\n';

    }
    return 0;
}