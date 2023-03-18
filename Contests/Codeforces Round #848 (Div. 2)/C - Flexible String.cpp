#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

string a, b;
int answ;
void count_matchs(vector<char>& curr){
    unordered_set<char> q;
    for(auto aux : curr) q.insert(aux);
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i] || q.count(a[i])){
            cnt++;
        }
        else{
            res += ((cnt)*(cnt + 1)) / 2;
            cnt = 0;
        }
    }
    res += ((cnt)*(cnt + 1)) / 2;
    answ = max(answ, res);
}

void solve(int idx, vector<char>& diffs,vector<char>& cur, int& k){
    if(cur.size() == k){
        count_matchs(cur);
        return;
    }
    if(idx == diffs.size()) return;

    cur.push_back(diffs[idx]);
    solve(idx + 1, diffs, cur, k);
    cur.pop_back();
    solve(idx + 1, diffs, cur, k);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        cin >> a >> b;

        unordered_set<char> uniques;
        for(auto aux : a) uniques.insert(aux);
        k = min(k, (int) uniques.size());
        vector<char> diffs;
        for(auto aux : uniques) diffs.push_back(aux);
        answ = 0;
        vector<char> aux;
        solve(0, diffs, aux, k);
        cout << answ << '\n';
    }
    return 0;
}