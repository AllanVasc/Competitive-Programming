#include <bits/stdc++.h>
using namespace std;

#define int long long
#define optimize ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(x) x.begin(), x.end()
#define pb push_back
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define iii tuple<int,int,int>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int ask(int t){
    cout << "? " << t << endl;
    int answ = 0;
    cin >> answ;
    return answ;
}
void giveAnsw(int m){
    cout << "! " << m << endl;
}
int32_t main() {
    optimize;
    
    for(int i = 1, steps = 0; steps < 42; i *= 2, steps++){
        int fdbck = ask(i);
        if(fdbck != i){
            giveAnsw(i - fdbck);
            return 0;
        }
    }

    return 0;
}