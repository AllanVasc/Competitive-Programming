#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        vector<int> desired(n);
        for(int i = 0; i < n; i++) cin >> desired[i];

        int m;
        cin >> m;
        vector<int> razors(m);
        for(int i = 0; i < m; i++) cin >> razors[i];

        bool valid = true;
        for(int i = 0; i < n; i++){
            if(v[i] < desired[i]) valid = false;
        }
        if(!valid){
            cout << "NO" << '\n';
        }
        else{
            stack<int> st;
            map<int,int> freq_need;
            for(int i = 0; i < n; i++){
                // cout << "olhando " << desired[i] << '\n';
                while(!st.empty() && st.top() < desired[i]){
                    int value = st.top();
                    freq_need[value]++;
                    st.pop();
                    // cout << "tirei da st " << value << '\n'; 
                }
                if(v[i] != desired[i] && st.empty()){
                    st.push(desired[i]);
                    // cout << "(1) botei " << desired[i] << '\n'; 
                }
                else if(v[i] != desired[i] && st.top() != desired[i]){
                    st.push(desired[i]);
                    // cout << "(2) botei " << desired[i] << '\n';
                }
            }
            while(!st.empty()){
                int value = st.top();
                freq_need[value]++;
                st.pop();
                // cout << "tirei da st " << value << '\n'; 
            }

            // cout << "PRECISO:" << '\n';
            // for(auto itr : freq_need){
            //     cout << itr.first << " = " << itr.second << '\n';
            // }
            valid = true;
            map<int,int> freq_have;
            for(auto i : razors){
                freq_have[i]++;
            }
            for(auto i : freq_need){
                if(i.second > freq_have[i.first]) valid = false;
            }
            
            cout << (valid ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}