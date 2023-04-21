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

    int ps, us;
    cin >> ps >> us;
    
    int n = ps + us;
    vector<int> pos(n + 1);
    set<int> pin;
    set<int> unpin;
    for(int i = 0; i < ps; i++){
        int x;
        cin >> x;
        pin.insert(x);
        pos[x] = i;
    }
    for(int j = 0; j < us; j++){
        int x;
        cin >> x;
        unpin.insert(x);
        pos[x] = j + ps;
    }

    int pe, ue;
    cin >> pe >> ue;
    vector<int> pinEnd;
    vector<int> unpinEnd;
    for(int i = 0; i < pe; i++){
        int x;
        cin >> x;
        pinEnd.push_back(x);
    }
    for(int i = 0; i < ue; i++){
        int x;
        cin >> x;
        unpinEnd.push_back(x);
    }

    int answ = 0;
    int last_val = -1;
    for(int i = ue - 1; i >= 0; i--){
        int curr = unpinEnd[i];
        if(pin.count(curr)){
            // preciso dar unpin
            answ++;
        }
        else{   // ele ja ta unpin
            if(last_val != -1 && pos[curr] > pos[last_val]){
                answ += 2;
            }
        }
        last_val = curr;
    }

    // cout << "unpin -> answ = " << answ << '\n';
    last_val = -1;
    for(int i = 0; i < pe; i++){
        int curr = pinEnd[i];
        if(unpin.count(curr)){
            answ++;
        }
        else{
            if(last_val != -1 && pos[curr] < pos[last_val]){
                answ += 2;
            }
        }
        last_val = curr;
    }

    cout << answ << "\n";
    return 0;
}