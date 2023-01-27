// L - Sticky Situation
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    sort(v.begin(), v.end());

    bool check = false;
    for(int i = 0; i < n-2; i++){
        if(v[i] + v[i+1] > v[i+2]) check = true;
    }

    if(check) cout << "possible" << '\n';
    else cout << "impossible" << '\n';

    return 0;
}
