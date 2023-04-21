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

    int t;
    cin >> t;
    vector<string> cloathes;
    while(t--){
        string s;
        cin >> s;
        if(s == "put"){
            string clot;
            cin >> clot;
            cloathes.push_back(clot);
        }
        else if(s == "get"){
            if(cloathes.size() == 0){
                cout << "empty" << '\n';
            }
            else{
                cout << cloathes.back() << '\n';
                cloathes.pop_back();
            }
        }
        else if(s == "iditarod"){
            bool found = false;
            for(int j = cloathes.size() - 1; j >= 0; j--){
                if(cloathes[j] == "snowcoat"){
                    found = true;
                    cout << "winner winner chicken dinner :)" << '\n';
                    cloathes.erase(cloathes.begin() + j);
                    break;
                }
            }
            if(!found){
                cout << "oopsimcold :(" << '\n';
            }
        }
    }

    return 0;
}