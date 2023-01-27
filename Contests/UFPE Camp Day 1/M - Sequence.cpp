// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    int maxi = LONG_LONG_MIN;
    int mini = LONG_LONG_MAX;

    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
        mini = min(mini, aux);
        maxi = max(maxi, aux);
    }

    cout << (maxi - mini)*n << '\n';
    return 0;
}
