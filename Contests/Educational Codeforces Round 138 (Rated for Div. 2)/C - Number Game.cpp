#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

bool check(int k, vector<int> v){
    int removed = 0;
    int n = v.size();
    int last = n - 1;
    for(int i = 0; i < n; i++){
        int sum = k - removed;
        if(v[i] <= sum){
            removed++;
            if(last >= 0){
                v[last] += sum;
                last--;
            }
        }
        if(removed == k) return true;
    }

    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end(), greater<int>());

        int l = 0;
        int r = 100;
        int answ = 0;

        while(l <= r){
            int m = l + (r - l)/2;

            if(check(m, v)){
                answ = m;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }

        cout << answ << '\n';
    }
    
    return 0;
}