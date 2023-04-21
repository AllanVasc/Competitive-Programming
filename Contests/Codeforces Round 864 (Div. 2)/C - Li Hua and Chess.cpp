#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int ask(int r, int c){
    cout << "? " << r << " " << c << endl;
    int answ;
    cin >> answ;
    return answ;
}

void resp(int r, int c){
    cout << "! " << r << " " << c << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int answ;
        
        int r1, c1, r2,c2, r3,c3;
        r1 = 1, c1 = 1;
        answ = ask(r1, c1);
        if(answ == 0){
            resp(r1, c1);
        }
        else{
            r2 = min(r1 + answ, n);
            c2 = min(c1 + answ, m);
            
            answ = ask(r2, c2);
            if(answ == 0){
                resp(r2, c2);
            }
            else{
                r3 = max(1LL, r2 - answ);
                c3 = c2;
                answ = ask(r3, c3);
                if(answ == 0){
                    resp(r3, c3);
                }
                else{
                    resp(r2, c2 - answ);
                }
            }
        }
    }
    return 0;
}