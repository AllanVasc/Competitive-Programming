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

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    while(q--){
        int k;
        cin >> k;

        int left = n - 1;
        int right = n - 1;
        int sum = 0;
        pair<int, int> answ = {0, INF};
        while(left >= 0){
            sum += v[left];
            while(right >= 0 && sum > k){
                sum -= v[right];
                right--;
            }
            if(sum == k){
                if(right - left < answ.second - answ.first){
                    answ.first = left;
                    answ.second = right;
                }
                else if((right - left == answ.second - answ.first) && left < answ.first){
                    answ.first = left;
                    answ.second = right;
                }
                // cout << "l = " << left << " r = " << right << '\n';
            }
            
            left--;
        }

        cout << answ.first << " " << answ.second << '\n';
    }

    return 0;
}