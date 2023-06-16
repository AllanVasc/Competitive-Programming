#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

bool check(string & s, int cost, vi & pref, vi & suff){
    int n = s.size();
    // cout << "cost = " << cost << '\n';
    for(int i = 0; i <= cost; i++){
        // cout << "i = " << i << '\n';
        int removed = pref[i] + suff[cost - i];
        // cout << "removed = " << removed << '\n';
        // left = quantos 0's sobraram
        int left = s.size() - (pref.size() - 1) - removed;
        // cout << "left = " << left << '\n';
        if(left <= cost) return true;
    }
    return false;
}

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vi pref, suff;
        pref.pb(0), suff.pb(0);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') pref.push_back(pref.back());
            else pref[pref.size() - 1]++;
        }
        for(int i = s.size() - 1; i>=0; i--){
            if(s[i] == '1') suff.pb(suff.back());
            else suff[suff.size() - 1]++;
        }
        // reverse(ALL(suff));
        // cout << "PREF = ";
        // for(auto x : pref) cout << x << " ";
        // cout << endl;
        // cout << "SUF = ";
        // for(auto x : suff) cout << x << " ";
        // cout << endl;

        int l = 0;
        int r = pref.size() - 1;
        int answ = INF;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(check(s, mid, pref, suff)){
                answ = min(answ, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        cout << answ << '\n';
    }
    return 0;
}