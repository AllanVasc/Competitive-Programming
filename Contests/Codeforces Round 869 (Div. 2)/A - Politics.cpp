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

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<string> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];

        int maxPeople = n;
        unordered_map<int, bool> mp;
        for(int i = 0; i < k; i++){
            int cntPlus = 0;
            int cntMinus = 0;
            for(int j = 0; j < n; j++){
                if(mp[j] == true) continue;
                if(v[j][i] == '+') cntPlus++;
                else cntMinus++;
            }
            
            if(v[0][i] == '+'){
                maxPeople = maxPeople - cntMinus;
                for(int j = 0; j < n; j++){
                    if(v[j][i] == '-') mp[j] = true;
                }
            }
            else{
                maxPeople = maxPeople - cntPlus;
                for(int j = 0; j < n; j++){
                    if(v[j][i] == '+') mp[j] = true;
                }
            }
        }
        cout << maxPeople << '\n';
    }
    return 0;
}