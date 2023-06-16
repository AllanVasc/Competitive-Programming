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

multiset<int> low;
multiset<int> up;
int lSum, rSum;
void insert(int x, int k){
    if(low.empty()){
        low.insert(x);
        lSum += x;
        return;
    }
    int median = *low.rbegin();
    if(x > median){
        up.insert(x);
        rSum += x;
        if(up.size() > k/2){
            low.insert(*up.begin());
            lSum += *up.begin();
            rSum -= *up.begin();
            up.erase(up.find(*up.begin()));     
        }
    }
    else{
        low.insert(x);
        lSum += x;
        if(low.size() > (k + 1) / 2){
            up.insert(*low.rbegin());
            rSum += *low.rbegin();
            lSum -= *low.rbegin();
            low.erase(low.find(*low.rbegin()));
        }
    }
}

void erase(int x, int k){
    if(up.count(x)){
        up.erase(up.find(x));
        rSum -= x;
    }
    else{
        low.erase(low.find(x));
        lSum -= x;
    }
    if(low.empty() && !up.empty()){
        low.insert(*up.begin());
        lSum += *up.begin();
        rSum -= *up.begin();
        up.erase(up.find(*up.begin()));
    }
}

int32_t main() {
    optimize;

    int n, k;
    cin >> n >> k;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int l = 0, r = 0;
    while(r < n){
        while(r < n && r - l < k){
            insert(v[r], k);
            r++;
        }
        int median = *low.rbegin();
        cout << low.size() * median - lSum +
                rSum - up.size() * median << " ";
        erase(v[l], k);
        l++;
    }
    cout << '\n';
    return 0;
}