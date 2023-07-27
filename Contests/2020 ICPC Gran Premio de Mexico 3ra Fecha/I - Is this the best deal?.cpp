#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> v(3);
    cin >> v[0] >> v[1] >> v[2];

    sort(v.rbegin(),v.rend());
    int ans = 0, acc = 0;
    
    if(v[0] >= 500){
        ans += v[0] - 100;
        if(v[1] >= 500){
            ans += v[1] - 100;
            if(v[2] >= 500) ans += v[2] -100;
            else ans += v[2];
        }
        else if(v[1] + v[2] >= 500) ans += v[1] + v[2] - 100;
        else ans += v[1] + v[2];
    }

    else{
        if(v[0] + v[1] + v[2] >= 500) ans += v[0] + v[1] + v[2] - 100;
        else ans += v[0] + v[1] + v[2];
    }

    cout << ans << "\n";

    return 0;
}