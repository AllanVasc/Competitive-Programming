#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> production;
bool check(int time, int k){
    int product = 0;
    for(int i = 0; i < production.size(); i++){
        product += time / production[i];
        if(product >= k) return true;
    }
    return false;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    vector<ii> events;
    for(int i = 0; i < n; i++){
        int duration, deadline;
        cin >> duration >> deadline;
        events.push_back({duration, deadline});
    }
    sort(events.begin(), events.end());
    int answ = 0;
    int curr_t = 0;
    for(int i = 0; i < n; i++){
        curr_t += events[i].first;
        answ += events[i].second - curr_t;
    }

    cout << answ << '\n';
    return 0;
}