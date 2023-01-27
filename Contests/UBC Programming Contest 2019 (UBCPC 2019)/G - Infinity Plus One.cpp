#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct Infinity{
    string s;
    vector<int> freq;

    Infinity(string s){
        freq.assign(120, 0);
        this->s = s;
        int n = s.size();
        int depth = 0;
        int greater = 0;

        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == ']'){
                if(s[st.top()] == '['){
                    s[i] = s[st.top()] = 'X';
                    st.pop();
                }
                continue;
            }
            st.push(i);
        }

        for(int i = 0; i < n; i++){
            if(s[i] == '[') depth++;
            else if(s[i] == ']') depth--;
            else if(s[i] == 'X') continue;

            greater = max(greater, depth);

            if(depth == 0){
                for(int j = 0; j < greater; j++) freq[j] = 0;
                freq[greater]++;
                greater = 0;
            }
        }
    }
};

void debug(Infinity aux){
    for(int i = 0; i < 10; i++){
        if(aux.freq[i])
            cout << "Frequency " << i << " = " << aux.freq[i] << '\n';
    }
}

bool comp(Infinity& a, Infinity& b){
    int n = a.freq.size();
    for(int i = n - 1; i >= 0; i--){
        if(a.freq[i] != b.freq[i]) return a.freq[i] < b.freq[i];
    }
    return false;
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    vector<Infinity> v;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;

        v.push_back(Infinity(s));
    }

    // cout << "antes:\n";
    // for(int i = 0; i < m; i++){
    //     cout << v[i].s << '\n';
    //     debug(v[i]);
    // }
    // cout << '\n';

    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < m; i++){
        cout << v[i].s << '\n';
    }

    return 0;
}