#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("buffcraft.in", "r", stdin);
    freopen("buffcraft.out", "w", stdout);

    int b, k, cd, cp;
    cin >> b >> k >> cd >> cp;

    vector <pair <int, int>> d(cd), p(cp);
    for(int i = 0; i < cd; i++){
        int x;
        cin >> x;

        d[i] = {x, i+1};
    }

    for(int i = 0; i < cp; i++){
        int x;
        cin >> x;

        p[i] = {x, i+1};
    }

    sort(d.rbegin(), d.rend());
    sort(p.rbegin(), p.rend());

    vector <int> pfd(cd + 1, b), pfp(cp + 1, 100);

    for(int i = 0; i < cd; i++){
        pfd[i+1] = pfd[i] + d[i].first; 
    }

    for(int i = 0; i < cp; i++){
        pfp[i+1] = pfp[i] + p[i].first; 
    }

    int mAns = b;
    int n = 0, m = 0;
    for(int i = 0; i <= k; i++){
        int ans = (pfd[min(i, cd)]) * (pfp[min(k - i, cp)]);
        if(ans > mAns){
            n = min(i, cd);
            m = min(k - i, cp);
            mAns = ans;
        }
    }

    cout << n << " " << m << "\n";
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << d[i].second;
    }
    cout << "\n";

    for(int i = 0; i < m; i++){
        if(i) cout << " ";
        cout << p[i].second;
    }
    cout << "\n";

    return 0;
}