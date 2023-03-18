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
        if(n % 2 == 0){
            cout << "No" << '\n';
        }
        else{
            cout << "Yes" << '\n';
            vector<iii> answ;
            int mid = 1 + 2 * n;
            answ.push_back({mid, 1, 2 * n});
            for(int i = 0; i < n/2; i++){
                int check = mid + (n/2 - i);
                answ.push_back({check, 2*n - 1 - i * 2, check - (2*n - 1 - i * 2)});
            }
            for(int i = 0; i < n/2; i++){
                int check = mid - (i + 1);
                answ.push_back({check, 2*n - 2 - (i * 2), check - (2*n - 2 - (i * 2))});
            }
            sort(answ.begin(), answ.end());
            for(int i = 0; i < answ.size(); i++){
                auto [sum, x, y] = answ[i];
                // cout << "sum = " << sum << '\n';
                cout << x << " " << y << '\n';
            }
        }
    }
    return 0;
}