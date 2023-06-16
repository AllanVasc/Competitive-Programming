#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool reversed = (s[0] == ')');
        int color = 0;
        vector<int> answ(n);
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(reversed){
                if(s[i] == ')'){
                    st.push(s[i]);
                    answ[i] = color;
                }
                else{
                    if(st.empty()){
                        reversed = !reversed;
                        color = !color;
                        answ[i] = color;
                        st.push(s[i]);
                    }
                    else{
                        st.pop();
                        answ[i] = color;
                    }
                }
            }
            else{
                // normal
                if(s[i] == '('){
                    st.push(s[i]);
                    answ[i] = color;
                }
                else{
                    if(st.empty()){
                        // problem
                        reversed = !reversed;
                        color = !color;
                        answ[i] = color;
                        st.push(s[i]);
                    }
                    else{
                        st.pop();
                        answ[i] = color;
                    }
                }
            }
        }

        if(!st.empty()){
            cout << -1 << '\n';
        }
        else{
            bool dif = false;
            for(int i = 1; i < n; i++){
                if(answ[i] != answ[i - 1]){
                    dif = true;
                }
            }
            if(dif){
                cout << 2 << '\n';
            }
            else{
                cout << 1 << '\n';
            }
            for(int i = 0; i < n; i++){
                cout << answ[i] + 1 << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}