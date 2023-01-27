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

    int n;
    cin >> n;

    int total = (1 + n) * n;

    if(total % 4 != 0){
        cout << "NO" << '\n';
    }
    else{
        total = total / 4;

        set<int> first;
        set<int> second;
        for(int i = n; i >= 1; i--){
            if(total >= i){
                first.insert(i);
                total -= i;
            }
            else{
                second.insert(i);
            }
        }

        cout << "YES" << '\n';
        cout << first.size() << '\n';
        for(auto i : first) cout << i << " ";
        cout << '\n';
        cout << second.size() << '\n';
        for(auto i : second) cout << i << " ";
        cout << '\n';
    }

    return 0;
}