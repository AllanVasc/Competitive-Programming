#include <bits/stdc++.h>

#define int long long
using namespace std;
long double eps = 1e-11;
const int  INF = 1e9;

int cmp(long double a, long double b){
    if(abs(a - b) <= eps) return 0;
    if(a > b) return 1;
    else return -1;
}

bool check(int mid, int n){
    long double answ = 1.0;
    long double cnt = 1;
    long double den = n;
    for(int i = 0; i < mid; i++){
        cnt *= (n - i) / (den);
    }
    answ -= cnt;
    return cmp(answ, 0.5) > 0;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    int answ = INF;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid, n)){
            answ = min(answ, mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << (answ == INF ? n + 1 : answ) << '\n';
    return 0;
}