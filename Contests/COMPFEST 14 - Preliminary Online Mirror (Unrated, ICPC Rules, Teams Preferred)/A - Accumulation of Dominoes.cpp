#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, m;
    cin >> n >> m;

    if(m == 1){
        cout << n-1 << "\n";
    }
    else{
        cout << n*(m-1) << "\n";
    }

    return 0;
}