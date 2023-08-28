#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <int> v(4);
    for(int i = 0; i < 4; i++){
        cin >> v[i];
    }

    int p;
    cin >> p;

    sort(v.begin(), v.end());

    if(v[1] != v[2] || v[2] != v[3]){
        cout << "0\n";
        return 0;
    }

    if(v[0] == v[1] || v[0] + p == v[1]){
        cout << "1\n";
    }

    else cout << "0\n";

    return 0;
}