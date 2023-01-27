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
    vector<ii> v;
    int sumx = 0, sumy = 0;
    bool can = true;
    map<ii,int> freq;
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
        sumx += a;
        sumy += b;
        freq[{a,b}]++;
    }
    if(n%2 != 0) can = false;

    if(sumx%(n/2) != 0 || sumy%(n/2) != 0) can = false;
    sumx /= (n/2);
    sumy /= (n/2);
    for(int i = 0; i < n && can; i++){
        if(freq[{sumx - v[i].first, sumy - v[i].second}] == 0) can = false;
        freq[{sumx - v[i].first, sumy - v[i].second}]--;
    }

    if(can) cout << "possible" << '\n';
    else cout << "impossible" << '\n';
    
    return 0;
}
