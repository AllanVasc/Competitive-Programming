// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<tuple<int,int,int>> times;

    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;

        // time, start/end, version
        times.push_back({start, 1, i});
        times.push_back({end, 2, i});
    }

    sort(times.begin(), times.end());

    set<int> curr;
    vector<int> answ;

    for(int i = 0; i < times.size(); i++){
        auto aux = times[i];
        
        int t = get<0>(aux);
        int command = get<1>(aux);
        int version = get<2>(aux);

        if(command == 1){ // só adiciono
            curr.insert(version);
        }
        else{ // Tenho que checar se já peguei essa versao ou n
            if(curr.count(version) != 0){
                answ.push_back(t);
                curr.clear();
            }
        }
    }

    cout << answ.size() << '\n';
    for(int i = 0; i < answ.size(); i++){
        cout << answ[i] << " ";
    }
    cout << '\n';

    return 0;
}