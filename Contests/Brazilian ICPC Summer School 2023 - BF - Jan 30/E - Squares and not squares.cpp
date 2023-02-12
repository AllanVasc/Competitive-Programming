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
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> squares;;
    for(int i = 0; i * i <= 2*1e9; i++){
        squares.push_back(i * i);
    }

    vector<ii> steps(n, {0,0} );
    for(int i = 0; i < n; i++){
        int curr_answ = INF;
        int value = v[i];

        auto itr = lower_bound(squares.begin(), squares.end(), value);
        if(itr != squares.begin()){
            curr_answ = min(curr_answ, value - *(prev(itr)) );
        }
        curr_answ = min(curr_answ, *itr - value);
        curr_answ = min(curr_answ, *(next(itr)) - value );

        steps[i] = {curr_answ, value};
    }

    // cout << "menores = ";
    // for(int i = 0; i < n; i++){
    //     cout << steps[i].first << " ";
    // }
    // cout << '\n';
    
    sort(steps.begin(), steps.end());
    int answ = 0;
    for(int i = 0; i < n / 2; i++){
        answ += steps[i].first;
    }

    for(int i = n / 2; i < n; i++){
        if(steps[i].first == 0){
            int value = steps[i].second;
            if(value == 0) answ += 2;
            else answ++;
        }
    }

    cout << answ << '\n';
    return 0;
}