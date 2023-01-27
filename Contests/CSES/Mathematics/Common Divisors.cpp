#include <bits/stdc++.h>
using namespace std;
  
#define int long long
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int ms = 1e6 + 10;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> freq(ms, 0);
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        freq[aux]++;
    }

    int answ = 1;
    for(int i = 2; i < ms; i++){
        int count = 0;
        for(int j = i; j < ms; j += i){
            if(freq[j]) count += freq[j];
        }
        if(count > 1) answ = i;
    }

    cout << answ << '\n';

    return 0;
}