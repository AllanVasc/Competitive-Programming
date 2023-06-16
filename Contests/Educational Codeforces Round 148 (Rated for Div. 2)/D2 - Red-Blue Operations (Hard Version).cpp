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

int pa(int l, int r){
    return (l + r) * (r - l + 1) / 2;
}

int32_t main() {
    optimize;
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(ALL(v));
    vector<int> minsPref(n), minsSuff(n);
    minsPref[0] = v[0] - 0;
    int sumArray = v[0];
    for(int i = 1; i < n; i++){
        minsPref[i] = min(minsPref[i - 1], v[i] - i);
        sumArray += v[i];
    }
    minsSuff[n - 1] = v[n - 1];
    for(int i = n - 2; i >= 0; i--){
        minsSuff[i] = min(minsSuff[i + 1], v[i]);
    }
    while(q--){
        int k; 
        cin >> k;

        int qttMinus = 0;
        int missOp = k - n;
        int topInc = k;
        int lessInc = max(1LL , k - n + 1);

        if(k > n){
            if(missOp & 1){
                missOp++;
                lessInc++;
            }
            qttMinus = missOp / 2; 
        }
        
        int mn = INF;
        mn = min(mn, minsPref[topInc - lessInc] + k);
        if(topInc - lessInc < n - 1){
            mn = min(mn, minsSuff[topInc - lessInc + 1]);
        }

        int currSum = sumArray + pa(lessInc, topInc);
        int low = mn - qttMinus;
        int high = mn;
        int answ = low;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(currSum - mid * n >= qttMinus){
                answ = max(answ, mid);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << answ << " ";
    }
    cout << '\n';
    return 0;
}