#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<ll,ll>> v;

    for(int i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    ll answ = LONG_LONG_MAX;
    for(int i = 0; i < n; i++){
        ll curr = (v[i].first * v[(i+1)%n].second + v[(i+1)%n].first * v[(i+2)%n].second + v[(i+2)%n].first*v[i].second) -
                    (v[i].second * v[(i+1)%n].first + v[(i+1)%n].second * v[(i+2)%n].first + v[(i+2)%n].second * v[i].first);

        if(curr < answ) answ = curr;  
    }

    cout << answ << endl;
    
}