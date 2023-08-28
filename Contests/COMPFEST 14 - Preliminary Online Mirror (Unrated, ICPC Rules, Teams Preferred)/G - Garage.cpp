#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1){
        cout << "3\n";
        return 0;
    }
    if(n == 2){
        cout << "5\n";
        return 0;
    }

    n -= 3;
    int bloco = n/3;
    int st = 7 + 4*bloco;

    cout << st + n % 3 << "\n";

    return 0;
}