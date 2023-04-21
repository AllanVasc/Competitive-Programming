#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

bool check(int val, int pid, int k){
    if(val >= pid - k && val <= pid + k) return true;
    else return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ii> v(n); // {fi, di}
        for(int i = 0; i < n; i++) cin >> v[i].first;
        for(int i = 0; i < n; i++) cin >> v[i].second;

        int answ = n;
        for(int i = 0; i < n; i++){
            int pid = v[i].first * v[i].second;
            vector<iii> events;
            events.push_back({pid, 1, i});
            // cout << "[" << pid - k << "," << pid + k << "]" << '\n';
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                auto [fi, di] = v[j];
                int v1 = max(1LL, pid / fi);
                int v2 = v1 + 1;
                int v3 = di;
                if(check(fi*v1, pid, k)) events.push_back({fi * v1, 0, j});
                if(check(fi*v2, pid, k)) events.push_back({fi * v2, 0, j});
                if(check(fi*v3, pid, k)) events.push_back({fi * v3, 1, j});
            }
            sort(events.begin(), events.end());
            // cout << "events: ";
            // for(auto [val, f, idx] : events) cout << "{" << val << "," << f << "," << idx << "} ";
            // cout << '\n'; 
            int cnt = 0;
            int l = 0;
            int r = 0;
            vector<int> freq(n, 0);
            int sz = 0;
            while(r < events.size()){
                while(get<0>(events[r]) - get<0>(events[l]) > k){
                    cnt -= get<1>(events[l]);
                    freq[get<2>(events[l])]--;
                    if(freq[get<2>(events[l])] == 0) sz--;
                    l++;
                }
                // cout << "sz = " << sz << '\n';
                cnt += get<1>(events[r]);
                freq[get<2>(events[r])]++;
                if(freq[get<2>(events[r])] == 1) sz++;
                if(sz == n) answ = min(answ, n - cnt);
                r++;
            }
            if(sz == n) answ = min(answ, n - cnt);
            // cout << "answ = " << answ <<'\n';
        }
        cout << answ << '\n';
    }
    return 0;
}