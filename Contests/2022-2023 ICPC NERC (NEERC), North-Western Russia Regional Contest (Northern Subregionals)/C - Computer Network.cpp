#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector <int> d(n);
    for(int i = 0; i < n; i++)
        cin >> d[i];

    sort(d.begin(), d.end());

    queue <int> lat;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i < k){
            ans += d[i];
            lat.push(d[i]);
        }
        else{
            int aux = lat.front();
            lat.pop();

            ans += d[i] + aux;
            lat.push(d[i] + aux);
        }
    }

    cout << ans << "\n";

    return 0;
}