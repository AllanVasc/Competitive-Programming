#include <bits/stdc++.h>
using namespace std;


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<string> linhas = { "QWERTYUIOP", 
                              "ASDFGHJKL",
                              "ZXCVBNM", };
    map<char, int> possible;
    int qtt = 0;
    for(int i = 0; i < 3; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == '*'){
                possible[linhas[i][j]] = true;
                qtt++;
            }
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        string s; cin >> s;
        set<char> conj;
        bool flag = true;
        for(int i = 0; i < s.size(); i++){
            if(!possible[s[i]]) flag = false;
            else conj.insert(s[i]);
        }
        cout << (flag && (conj.size() == qtt) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
    }
    return 0;
}