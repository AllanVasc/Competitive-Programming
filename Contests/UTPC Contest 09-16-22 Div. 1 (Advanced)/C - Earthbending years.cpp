// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n, 0);

    for(int i = 0; i < n; i++) cin >> v[i];

    int carry = k;
    int count = 0;
    while(carry || count < n){
        if(count < n) carry += v[count];

        cout << (carry) % 4 << " ";
        carry = carry/4;

        count++;
    }

    cout << '\n';

    return 0;
}