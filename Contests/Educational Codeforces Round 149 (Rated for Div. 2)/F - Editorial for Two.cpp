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

bool check(int lim, vector<int> & v, int k){
    int n = v.size();
    priority_queue<int> pq;
    vector<int> prefix(n), suffix(n);
    int sum = 0;
    // cout << "prefix: " << '\n';
    for(int i = 0; i < n; i++){
        sum += v[i];
        pq.push(v[i]);
        while(!pq.empty() && sum > lim){
            sum -= pq.top();
            pq.pop();
        }
        prefix[i] = pq.size();
        // cout << "i = " << i << " " << prefix[i] << '\n';
    }
    sum = 0;
    while(!pq.empty()) pq.pop();
    // cout << "suffix" << '\n';
    for(int i = n - 1; i >= 0; i--){
        sum += v[i];
        pq.push(v[i]);
        while(!pq.empty() && sum > lim){
            sum -= pq.top();
            pq.pop();
        }
        suffix[i] = pq.size();
        // cout << "i = " << i << " " << suffix[i] << '\n';
    }

    for(int i = 0; i < n; i++){
        int totalPref = prefix[i];
        int totalSuff = (i == n - 1 ? 0 : suffix[i + 1]);
        if(totalPref + totalSuff >= k) return true;
    }
    return false;
}

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int left = v[0];
        int right = 0;
        for(int i = 0; i < n; i++){
            right += v[i];
            left = min(left, v[i]);
        }

        int answ = right;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(check(mid, v, k)){
                answ = min(answ, mid);
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        cout << answ << '\n';
    }
    return 0;
}