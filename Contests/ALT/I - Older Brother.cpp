// I - Older Brother 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const ll INF = 1e9 + 7;

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    set<int> primes;

    int aux = q;
    for(int i = 2; i*i <= q; i++){
        while(aux%i == 0){
            primes.insert(i);
            aux = aux/i;
        }
    }
    if(aux != 1) primes.insert(aux);

    if(primes.size() == 1) cout << "yes\n";
    else cout << "no\n";
    return 0;
}