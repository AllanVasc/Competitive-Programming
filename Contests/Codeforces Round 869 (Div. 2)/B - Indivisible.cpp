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

bool check(vector<int> & v){
    int n = v.size();
    for(int range = 2; range < n; range++){
        for(int i = 0; i <= n - range; i++){
            int currSum = 0;
            for(int j = i; j < min(i + range, n); j++){
                currSum += v[j];
            }
            if((currSum % (range)) == 0){
                return false;
            }
        }
    }
    return true;
}
int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) v[i] = i + 1;
        if(n == 1){
            cout << "1\n";
        }
        else if(n % 2){
            cout << -1 << '\n';
        }
        else{
            int first = 2;
            int second = 1;
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    v[i] = first;
                    first += 2;
                }
                else{
                    v[i] = second;
                    second += 2;
                }
            }
            if(check(v)){
                for(int i = 0; i < n; i++){
                    cout << v[i] << " ";
                }
                cout << '\n';
            }
            else{
                cout << -1 << '\n';
            }
        }
    }
    // do{
    //     if(check(v)){
    //         for(int i = 0; i < n; i++){
    //             cout << v[i] << " ";
    //         }
    //         cout << '\n';
    //     }
    // }
    // while(next_permutation(v.begin(), v.end()));
    return 0;
}