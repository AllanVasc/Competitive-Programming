#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    vector<iii> interval; // {tempo, chegada/saida, idx}
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        interval.push_back({a, 0, i});
        interval.push_back({b, 1, i});
    }

    sort(interval.begin(), interval.end());
    vector<int> answ(n, -1);
    int size = 0;
    int maxs = 0;
    set<int> freeRooms;
    for(int i = 1; i <= 2*1e5 + 10; i++) freeRooms.insert(i);

    for(int i = 0; i < interval.size(); i++){
        auto [time, command, idx] = interval[i];
        if(command == 0){
            size++;
            answ[idx] = *freeRooms.begin();
            freeRooms.erase(freeRooms.begin());
            maxs = max(maxs, size);
        }
        else{
            size--;
            freeRooms.insert(answ[idx]);
        }
    }

    cout << maxs << '\n';
    for(int i = 0; i < n; i++){
        cout << answ[i] << " ";
    }
    cout << '\n';

    return 0;
}