#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

bool check(string& s1, string& s2){
    bool valid = true;
    for(int i = 1; i < s1.size(); i++){
        if(s1[i] == s1[i - 1]) valid = false;
    }
    for(int i = 1; i < s2.size(); i++){
        if(s2[i] == s2[i - 1]) valid = false;
    }
    return valid;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string orig1, orig2;
        cin >> orig1 >> orig2;

        bool has_answ = false;
        string aux1 = orig1;
        string aux2 = orig2;
        while(!aux2.empty()){
            if(check(aux1, aux2)){
                has_answ = true;
            }
            char last = aux2.back();
            aux2.pop_back();
            aux1.push_back(last);
        }
        aux1 = orig2;
        aux2 = orig1;
        while(!aux2.empty()){
            if(check(aux1, aux2)){
                has_answ = true;
            }
            char last = aux2.back();
            aux2.pop_back();
            aux1.push_back(last);
        }
        if(has_answ){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}