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

const int ms = 1e5 + 100;

void apply(int inc, vector<int> & sum, vector<int> & factors){
    int n = factors.size();
    for(int mask = 1; mask < (1 << n); mask++){
        int qtt = __builtin_popcount(mask);
        int val = 1;
        for(int j = 0; j < n; j++) if(mask & (1 << j)) val *= factors[j];
        if(qtt % 2) sum[val] += inc;
        else sum[val] -= inc;
    }
}

int countMember(vector<int> & sum, vector<int> & factors){
    int n = factors.size();
    int answ = 0;
    for(int mask = 1; mask < (1 << n); mask++){
        int qtt = __builtin_popcount(mask);
        int val = 1;
        for(int j = 0; j < n; j++) if(mask & (1 << j)) val *= factors[j];
        answ += sum[val];
    }
    return answ;
}

signed main() {
    optimize;

    vector<vector<int>> factors(ms + 1);
    vector<bool> isPrime(ms + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= ms; i++){
        if(!isPrime[i]) continue;
        for(int j = i; j <= ms; j += i){
            isPrime[j] = false;
            factors[j].push_back(i);
        }
    }

    // for(int i = 2; i <= 20; i++){
    //     cout << i << " = ";
    //     for(auto x : factors[i]) cout << x << " ";
    //     cout << '\n';
    // }
    
    int n, q;
    cin >> n >> q;
    vector<int> need(n + 1);
    for(int i = 1; i <= n; i++) cin >> need[i];
    vector<pii> queries;
    for(int i = 0; i < q; i++){
        int cq, dq; cin >> cq >> dq;
        queries.push_back({cq, dq});
    }

    vector<int> L(n + 1, 0), R(n + 1, q - 1);
    vector<int> answ(n + 1, q);
    bool f = true;
    while(f){
        f = false;
        vector<int> sum(ms + 1, 0);
        vector<vector<int>> check(q);
        for(int i = 1; i <= n; i++){
            if(L[i] > R[i]) continue;
            f = true;
            int mid = (L[i] + R[i]) >> 1;
            check[mid].push_back(i);
        }
        for(int i = 0; i < q; i++){
            auto [cq, dq] = queries[i];
            apply(dq, sum, factors[cq]);
            for(auto member : check[i]){
                int cnt = countMember(sum, factors[member]);
                if(cnt >= need[member]){
                    answ[member] = min(answ[member], i);
                    R[member] = i - 1;
                }
                else L[member] = i + 1;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << (answ[i] == q ? -1 : answ[i] + 1) << '\n';
    }
    return 0;
}