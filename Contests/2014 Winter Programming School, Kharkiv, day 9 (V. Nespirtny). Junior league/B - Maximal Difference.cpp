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
    if(n == 1){
        cout << 0 << '\n';
    }
    else{
        string first(n, '0');
        string second(n, '0');
        
        for(int i = 0, j = n - 1; i < n; i++, j--){
            if(i == j){ // n odd
                first[i] = '1';
                second[0] = '1';
                break;
            }
            if(i > j){  // n even
                second[j + 1] = '8';
                second[0] = '1';
                break;
            }
            first[i] = '9';
            second[j] = '9';
        }
        // cout << first << " " <<  second << '\n';

        cout << abs(stoll(first) - stoll(second)) << '\n';
    }
    return 0;
}