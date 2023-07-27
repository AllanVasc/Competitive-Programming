#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ii pair<int,int>

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];

    sort(v.begin(), v.end());
   
    int rem =0;

    while(v.size() >=2 && v.back() + v[v.size()-2] > x){
        rem++;
        v.pop_back();
    }
    cout << n - rem << endl;


    return 0;
}