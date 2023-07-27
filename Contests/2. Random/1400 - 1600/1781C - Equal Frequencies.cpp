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

pair<int, set<char>> check(int qtt, int n, vector<int> & freq, bool debug){
    priority_queue<pair<int, char>> pq;
    for(int i = 0; i < freq.size(); i++){
        pq.push({freq[i], i + 'a'});
    }
    int need = n / qtt;
    if(debug) cout << "tentando block de " << qtt << endl;
    if(debug) cout << "Vou precisar = " << need << endl;
    int answ = 0;
    int total = 0;
    set<char> used;
    int extra = 0;
    while(qtt--){
        auto[curr, ch] = pq.top();
        if(debug) cout << "curr = " << curr << " ch = " << char(ch) << endl;
        pq.pop();
        if(curr > need){
            extra += curr - need;
            answ += curr - need;
        }
        else{ // curr < need
            int fill = min(curr + extra, need);
            extra -= (fill - curr);
            answ += need - fill;
            if(debug) cout << "fill = " << fill << endl;
        }
        if(debug){
            cout << "answ = " << answ << endl;
            cout << "extra = " << extra << endl;
        }
        used.insert(ch);
    }
    if(debug) cout << "answ = " << answ << endl;
    return {answ, used};
}

signed main() {
    optimize;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> freq(26, 0);
        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }

        int answ = INF;
        int need = INF; // qtt char
        set<char> chs;
        // check(4, n, freq, true);
        for(int i = 1; i <= 26; i++){ // letras que vao existir
            if(n % i == 0){
                // cout << "testando com " << i << endl;
                auto[curr, used] = check(i, n, freq, false);
                if(curr < answ){
                    answ = curr;
                    need = i;
                    chs = used;
                }
            }
        }
        // cout << "answ = " << answ << " blocks = " << need << endl;
        // cout << "VOU USAR: ";
        // for(auto x : chs) cout << x << " ";
        // cout << endl;
        
        string final(n, '*');
        vector<int> cnt(26, 0);
        int qtt = n / need;
        for(int i = 0; i < n; i++){
            if(chs.count(s[i]) && cnt[s[i] - 'a'] != qtt){
                final[i] = s[i];
                cnt[s[i] - 'a']++;
            }
        }
        // cout << "primeira passada fiquei com: " << final << endl;
        for(int i = 0; i < n; i++){
            if(final[i] == '*'){
                char nxt = *chs.begin();
                while(cnt[nxt - 'a'] == qtt){
                    chs.erase(nxt);
                    nxt = *chs.begin();
                }
                cnt[nxt - 'a']++;
                final[i] = nxt;
            }
        }
        cout << answ << endl;
        cout << final << endl;
    }
    return 0;
}