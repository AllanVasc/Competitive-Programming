#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<bool> is_prime(20, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i < 20; i++){
        if(is_prime[i]){
            for(int j = i * i; j < 20; j+= i){
                is_prime[j] = false;
            }
        }
    }
    set<int> primes;
    for(int i = 0; i < 20; i++){
        if(is_prime[i]) primes.insert(i);
    }
    // cout << "primes = " << '\n';
    // for(auto x : primes) cout << x << '\n';
    
    vector<int> possibles;
    for(int i = 0; i <= 1e6; i++){
        int qtd_ones = __builtin_popcount(i);
        if(primes.count(qtd_ones)) possibles.push_back(i);
    }
    //cout << "len = " << possibles.size() << '\n';
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int answ = 0;
        // for(int i = 0; i < possibles.size(); i++){
        //     if(possibles[i] >= l && possibles[i] <= r) answ++;
        // }

        int pos_r = lower_bound(possibles.begin(), possibles.end(), r) - possibles.begin();
        if(possibles[pos_r] > r) pos_r--;
        int pos_l = lower_bound(possibles.begin(), possibles.end(), l) - possibles.begin();
        answ = pos_r - pos_l + 1;
        cout << answ << '\n';
    }
    return 0;
}