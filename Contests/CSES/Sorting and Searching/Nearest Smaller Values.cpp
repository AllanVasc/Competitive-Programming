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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }
        if(st.empty()) cout << 0 << " ";
        else cout << st.top() + 1 << " ";
        st.push(i); 
    }
    cout << '\n';
    return 0;
}