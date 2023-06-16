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

map<multiset<int>, int> dp[20];
int solve(int suffixSize, multiset<int> partition){
    if(suffixSize == 0){
        return *partition.rbegin();
    }
    if(dp[suffixSize].count(partition)){
        return dp[suffixSize][partition];
    }
    int answ = 0;
    multiset<int> backup = partition;
    for(auto i : partition){
        backup.erase(backup.find(i));
        backup.insert(i + 1);

        answ += solve(suffixSize - 1, backup);

        backup.erase(backup.find(i + 1));
        backup.insert(i);
    }
    return dp[suffixSize][partition] = answ;
}

int count(int x){
    int answ = 0;
    string number = to_string(x);
    int n = number.size();
    vector<int> freq(10, 0);
    for(int i = 0; i < n; i++){
        int curr_val = number[i] - '0';
        for(int j = 0; j < curr_val; j++){
            if(i == 0 && j == 0) continue;
            freq[j]++;
            multiset<int> aux;
            for(int k = 0; k < 10; k++){
                aux.insert(freq[k]);
            }
            answ += solve(n - (i + 1),aux);
            freq[j]--;
        }
        freq[curr_val]++;
    }
    // Falta contar os numeros com menos digitos que "n"
    
    for(int i = 1; i < n; i++){
        //cout << "digits = " << i << " deu " << solve(i, aux) << '\n';
        multiset<int> aux;
        if(i == 1){
            answ += 9;
        }
        else{
            aux.insert(1);
            for(int j = 0; j < 9; j++){
                aux.insert(0);
            }
            answ += 9 * solve(i - 1, aux);
        }
    }
    return answ + (x > 0);
}

int32_t main() {
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int answ = count(r + 1) - count(l);
        cout << answ << '\n';
    }

    return 0;
}