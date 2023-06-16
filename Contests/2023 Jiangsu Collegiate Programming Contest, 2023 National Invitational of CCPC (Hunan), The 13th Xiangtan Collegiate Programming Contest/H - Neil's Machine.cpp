#include <bits/stdc++.h>

using namespace std;
                                 
#define pb push_back

typedef long long ll;


int n;
string s, t;

void solve(){
    cin >> n;
    cin >> s >> t;

    int buff = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int init = (s[i] - 'a' + buff)%26;
        int goal = t[i] - 'a';

        //cout << init << " " << goal << endl;
        if(goal > init){
            buff += goal - init;
            ans++;
        }else if(goal < init){
            buff += goal + 26 - init;
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}