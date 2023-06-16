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
        int n;
        cin >> n;
        vi a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        int idxStart;
        int idxLimit = -1;
        for(int i = 0; i < n && idxLimit == -1; i++){
            if(a[i] != b[i]){
                idxStart = i;
                for(int j = i + 1; j < n; j++){
                    if(b[j] < b[j - 1]) break;
                    idxLimit = j;
                }
            }
        }
        for(int i = idxStart - 1; i >= 0; i--){
            if(b[i] > b[i + 1]) break;
            idxStart = i;
        }
        cout << idxStart + 1 << " " << idxLimit + 1 << '\n';
    }
    return 0;
}