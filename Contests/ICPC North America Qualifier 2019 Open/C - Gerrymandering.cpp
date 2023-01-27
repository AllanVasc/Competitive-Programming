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
    
    int p,d;
    cin >> p >> d;

    vector<ii> v(d, {0,0});
    for(int i = 0; i < p; i++){
        int idx,a,b;
        cin >> idx >> a >> b;
        v[idx-1] = {v[idx-1].first + a, v[idx-1].second + b};
    }

    int wasted_a = 0;
    int wasted_b = 0;
    int total = 0;
    for(int i = 0; i < d; i++){
        if(v[i].first > v[i].second){
            cout << "A ";
            wasted_a += v[i].first - ((v[i].first + v[i].second)/2 + 1);
            wasted_b += v[i].second;

            cout << v[i].first - ((v[i].first + v[i].second)/2 + 1) << " ";
            cout << v[i].second << '\n';
        }
        else{
            cout << "B ";
            wasted_a += v[i].first;
            wasted_b += v[i].second - ((v[i].first + v[i].second)/2 + 1);

            cout << v[i].first << " ";
            cout << v[i].second - ((v[i].first + v[i].second)/2 + 1) << '\n';
        }
        total += v[i].first + v[i].second;
    }

    cout << fixed << setprecision(10);
    cout << abs(wasted_a - wasted_b)/double(total) << '\n';
    return 0;
}
