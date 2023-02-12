#include <bits/stdc++.h>
using namespace std;
  

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
	tree_order_statistics_node_update> indexed_set;

indexed_set s;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<iii> events;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        events.push_back({l, 0, i + 1});
        events.push_back({r, 1, i + 1});
    }
    sort(events.rbegin(), events.rend());
    // for(int i = 0; i < events.size(); i++){
    //     auto [value, cmd, idx] = events[i];
    //     cout << value << " " << cmd << " " << idx << '\n';
    // }

    vector<int> answ(n, -1);
    for(int i = 1; i <= n; i++){
        while(!events.empty()){
            auto [value, cmd, idx] = events.back();
            if(value == i && cmd == 0){
                s.insert(idx);
                events.pop_back();
            }
            else break;
        }
        if(s.size() >= i) answ[i - 1] = *s.find_by_order(i - 1);
        while(!events.empty()){
            auto [value, cmd, idx] = events.back();
            if(value == i && cmd){
                s.erase(idx);
                events.pop_back();
            }
            else break;
        }
    }

    for(auto i : answ) cout << i << " ";
    cout << '\n';
    return 0;
}