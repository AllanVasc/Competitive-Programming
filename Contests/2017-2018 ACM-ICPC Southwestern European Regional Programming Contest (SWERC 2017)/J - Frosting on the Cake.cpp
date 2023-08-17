#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector <int> A(3, 0), ans(3, 0);

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        A[i % 3] += x;
    }

    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        ans[i % 3] += x * (A[0]);
        ans[(i + 1) % 3] += x * (A[1]);
        ans[(i + 2) % 3] += x * (A[2]);
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";

    return 0;
}