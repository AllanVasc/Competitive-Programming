// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int steps;
    int answ;
    for(int i = 0; i < 101; i++){
        if((n+i)%100 == 99){
            steps = i;
            answ = n+i;
            break;
        }
        if((n-i)%100 == 99){
            steps = i;
            answ = n-i;
            // cout << "n-i = " << n-i << '\n';
            break;
        }
    }

    cout << answ << '\n';

    return 0;
}