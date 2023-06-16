#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector <int> ps(n+1, 0);

    for(int i = 0; i < n; i++){
        cin >> ps[i+1];
        ps[i+1] += ps[i];
    }

    int t = 0, val = 0, m = 0;
    bool broke = false;
    for(int i = 1; i <= n; i++){
        
        if(ps[i] + val < 0){
            if(m > 0){  
                int x = (abs(ps[i] + val) + m - 1) / m;
                val += m * x;
                t += x;
            }
            else{
                broke = true;
                break;
            }
        }
        val += ps[i];

        m = max(m, ps[i]);
        t++;
    }

    if(broke || ps[n] < 0) cout << "-1\n";
    else cout << t << "\n";


    return 0;
}