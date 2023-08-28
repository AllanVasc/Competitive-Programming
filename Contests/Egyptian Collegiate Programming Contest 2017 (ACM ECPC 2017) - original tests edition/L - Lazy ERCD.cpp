#include <bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("lazy.in", "r", stdin);
    int t;
    cin >> t;
    int cs = 1;
    while(t--){
        int n;
        cin >> n;
        cout << "Case " << cs++ << ": " << n-1 << '\n';
    }
}