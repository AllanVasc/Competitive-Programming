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
        vector<int> sequence;
        while(n != 1){
            if( (n - 1) % 2 == 0 && ((n - 1)/2) % 2 == 1){
                sequence.push_back(2);
                n = (n - 1) / 2;
            }
            else if((n + 1) % 2 == 0 && ((n + 1)/2) % 2 == 1){
                sequence.push_back(1);
                n = (n + 1) / 2;
            }
            else break;
        }
        if(n == 1){
            reverse(sequence.begin(), sequence.end());
            cout << sequence.size() << '\n';
            for(auto x : sequence) cout << x << " ";
            cout << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}