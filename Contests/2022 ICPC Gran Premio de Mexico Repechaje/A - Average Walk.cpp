#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int x;
    cin >> x;

    cout << min(15LL, ((x + 2999) / 3000)) << '\n';
    return 0;
}