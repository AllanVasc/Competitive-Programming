// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<ii> v;
    for(int i = 0; i < 2*n; i++){
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        v.push_back({a,b});
    }

    int answ = 0;
    vector<int> contribution;
    for(int i = 0; i < 2*n; i++){
        contribution.push_back(v[i].first + v[i].second);
        answ += v[i].second;
    }
    
    sort(contribution.begin(), contribution.end());
    for(int i = 0; i < n; i++){
       answ -= contribution[i]; 
    }

    cout << answ << '\n';
    
    return 0;
}
