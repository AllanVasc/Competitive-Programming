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

class SuffixArray{
public:
    string text;
    vector<int> sa;
    vector<int> rank;
    vector<int> lcp;

    void process(string & s){
        text = s;
        text += '$';
        int n = text.size();
        sa.resize(n);
        rank.resize(n);

        vector<pii> list;
        for(int i = 0; i < n; i++){
            list.push_back({text[i], i});
        }
        sort(list.begin(), list.end());
        for(int i = 0; i < n; i++) sa[i] = list[i].second;
        rank[sa[0]] = 0;
        int classe = 0;
        for(int i = 1; i < n; i++){
            if(text[sa[i]] != text[sa[i - 1]]) classe++;
            rank[sa[i]] = classe;
        }
        
        int k = 1;
        while(k < n){
            vector<int> aux(n);
            vector<int> count(n, 0);
            for(int i = 0; i < n; i++) count[rank[i]]++;
            for(int i = 1; i < n; i++) count[i] += count[i - 1];
            for(int i = n - 1; i >= 0; i--){
                int idx = (sa[i] - k + n) % n;
                aux[count[rank[idx]] - 1] = idx;
                count[rank[idx]]--;
            }
            swap(sa, aux);
            aux[sa[0]] = 0;
            classe = 0;
            for(int i = 1; i < n; i++){
                if(rank[sa[i]] != rank[sa[i - 1]] ||
                   rank[(sa[i] + k) % n] != rank[(sa[i - 1] + k) % n]){
                    classe++;
                }
                aux[sa[i]] = classe;
            }
            swap(rank, aux);
            k += k;
        }
    }
};

signed main() {
    optimize;
    string s;
    cin >> s;
    SuffixArray sa;
    sa.process(s);
    for(int i = 0; i < sa.sa.size(); i++){
        cout << sa.sa[i] << " ";
    }
    cout << '\n';
    return 0;
}