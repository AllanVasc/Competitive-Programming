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

    string s;
    cin >> s;

    int n = s.size();

    vector<int> freq(26, 0);
    for(int i = 0; i < n; i++){
        freq[s[i] - 'A']++;
    }

    int qtd_impar = 0;
    for(int i = 0; i < freq.size(); i++){
        if(freq[i] % 2 == 1) qtd_impar++;
    }

    if(n % 2 == 0 && qtd_impar > 0){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }
    else if(n % 2 == 1 && qtd_impar != 1){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }
    else{
        vector<char> answ;
        char middle;
        for(int i = 0; i < freq.size(); i++){
            if(freq[i] % 2 == 1){
                middle = char(i + 'A');
                freq[i]--;
            }
            while(freq[i]){
                answ.push_back(char(i + 'A'));
                freq[i] -= 2;
            }
        }

        if(qtd_impar){
            for(int i = 0; i < answ.size(); i++) cout << answ[i];
            cout << middle;
            for(int i = answ.size() - 1; i >= 0; i--) cout << answ[i];
        }
        else{
            for(int i = 0; i < answ.size(); i++) cout << answ[i];
            for(int i = answ.size() - 1; i >= 0; i--) cout << answ[i];
        }
        cout << '\n';
    }

    return 0;
}