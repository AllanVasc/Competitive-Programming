#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <int> p, v;
int n, m;

bool check(int d){
    int ans = 0;

    for(int i = 0; i < n; i++){
        ans = max(ans, min(ans + min(v[i] * d, (long long) 1e15) - p[i], (long long)1e15));
    }

    return ans >= m;
}

int32_t main(){
    cin >> n >> m;

    p.resize(n);
    v.resize(n);

    for(int i = 0; i  < n; i++){
        cin >> v[i] >> p[i];
    }

    int l = 1, r = 1e10;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid;
        }
        else l = mid + 1;
    }

    cout << l << "\n";

    return 0;
}