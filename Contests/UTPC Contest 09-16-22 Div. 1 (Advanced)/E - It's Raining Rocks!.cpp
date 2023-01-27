#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> pos;

bool check(int w, int qtd){
    int n = pos.size();

    int needed = 0;
    for(int i = 0; i < n;){
        int pivo = pos[i];
        int r = i+1;
        while(r < n){
            if(pos[r] - pivo + 1 > w){
                break;
            }
            r++;
        }
        i = r;
        needed++;
    }

    return needed <= qtd;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    pos.assign(n, 0);
    for(int i = 0; i < n; i++) cin >> pos[i];

    sort(pos.begin(), pos.end());

    int l = 1;
    int r = 1e9 + 5;
    int answ = 1e9;
    while(l <= r){
        int mid = l + (r-l)/2;

        if(check(mid, k)){
            answ = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << answ << '\n';

    return 0;
}