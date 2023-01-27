#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int answ = 0;
    int a = 0, c = 0, g = 0, t = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'A'){
            a++;
            c = 0;
            g = 0;
            t = 0;
        }
        else if(s[i] == 'C'){
            a = 0;
            c++;
            g = 0;
            t = 0;
        }
        else if(s[i] == 'G'){
            a = 0;
            c = 0;
            g++;
            t = 0;
        }
        else if(s[i] == 'T'){
            a = 0;
            c = 0;
            g = 0;
            t++;
        }

        answ = max(answ, a);
        answ = max(answ, c);
        answ = max(answ, g);
        answ = max(answ, t);
    }

    cout << answ << '\n';
    return 0;
}