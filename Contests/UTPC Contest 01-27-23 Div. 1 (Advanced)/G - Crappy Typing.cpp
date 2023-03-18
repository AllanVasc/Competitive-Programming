#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> times;
bool check(int m, int limit){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < m; i++) pq.push(0);
    int n = times.size();
    for(int i = 0; i < n; i++){
        int curr = pq.top();
        pq.pop();
        pq.push(curr + times[i]);
    }
    int answ = 0;
    while(!pq.empty()){
        int curr = pq.top();
        pq.pop();
        answ = max(answ, curr);
    }
    return (answ <= limit);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, d;
    cin >> n >> d;
    times.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> times[i];

    int l = 1;
    int r = 1e5 + 10;
    int answ = 0;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid, d)){
            answ = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << answ << '\n';
    return 0;
}