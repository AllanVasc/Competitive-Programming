#include <bits/stdc++.h>

using namespace std;

#define int long long


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int w, n;
    cin >> w >> n;
    int tot=0;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        tot += a*b;
    }
    cout << tot/w << endl;

}