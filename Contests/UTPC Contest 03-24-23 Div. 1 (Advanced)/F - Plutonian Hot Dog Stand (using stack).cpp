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
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    stack<ii> st;
    for(int i = n - 1; i >= 0; i--){
        int cnt = 1;
        while(!st.empty()){
            auto [val, qtd] = st.top();
            if(val <= v[i]){
                cnt += qtd;
                st.pop();
            }
            else{
                break;
            }
        }
        // cout << "v[i] = " << v[i] << " cnt = " << cnt << '\n';
        st.push({v[i], cnt});
    }
    vector<int> better;
    while(!st.empty()){
        auto [val, cnt] = st.top();
        st.pop();
        better.push_back(cnt);
    }
    sort(better.begin(), better.end(), greater<int>());
    int answ = 0;
    for(int i = 0; i < better.size() && i < d; i++){
        answ += better[i];
    }
    cout << answ << '\n';
    return 0;
}