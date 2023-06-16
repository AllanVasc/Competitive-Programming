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
        vector<int> v;
        bool flag = false;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            if(v.size() == 0){
                v.push_back(x);
                cout << 1;
            }
            else{
                if(!flag){
                    if(x >= v.back()){
                        v.push_back(x);
                        cout << 1;
                    }
                    else{
                        if(x > v[0]){
                            cout << 0;
                            continue;
                        }
                        else{
                            v.push_back(x);
                            cout << 1;
                            flag = true;
                        }
                    }
                }
                else{
                    if(x >= v.back() && x <= v[0]){
                        cout << 1;
                        v.push_back(x);
                    }
                    else{
                        cout << 0;
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}