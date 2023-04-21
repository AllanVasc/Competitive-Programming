#include<bits/stdc++.h>
using namespace std;

#define int long long
using ii = pair<int,int>;
const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, a, b;
    cin >> n >> a >> b;

    int answ = INF;
    for(int i = 1; i <= 1000; i++){
        for(int j = i + 1; j <= 1000; j++){
            if(i * a + b * j > n) continue;
            answ = min(answ, n - (i * a + b * j));
        }
    }
    cout << answ << '\n';

    return 0;
}