#include <bits/stdc++.h>

using namespace std;

#define int long long



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    bool ans = false;
    int h, w;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(j*j + i*i == n) {
                ans = true;
                h = i;
                w = j;
            }
        }
    }

    if(!ans){
        cout << "Impossible\n";
    }
    else{
        int x = 0, y = 0;

        cout << x << " " << y << '\n';
        cout << x+w << " " << y+h <<'\n';
        cout << x+h << " " << y - w << '\n';
        cout << x + h + w << " " << y - w + h << '\n';
    }
}