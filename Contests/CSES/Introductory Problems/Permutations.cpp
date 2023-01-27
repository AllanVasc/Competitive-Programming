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

    if(n == 1){
        cout << 1 << '\n';
    }
    else if(n < 4){
        cout << "NO SOLUTION" << '\n';
    }
    else if(n == 4){
        cout << "2 4 1 3" << '\n';
    }
    else{
        int i;
        for(i = 0; i < n/2.0; i++){
            cout << 1 + i*2 << " ";
        }

        for(; i < n; i++){
            cout << 2 + 2*(int)(i - (n+1)/2) << " ";
        }
        cout << '\n';
    }

    return 0;
}