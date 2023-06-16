#include<bits/stdc++.h>
using namespace std;

#define int long long

string nextString(string s){
    string answ;
    for(int i = 0; i < s.size(); i++){
        char curr = s[i];
        if(curr == 'z') curr = 'a';
        else curr++;
        answ.push_back(curr);
    } 
    return answ;
}

int fexp(int x, int y, int mod){
    int answ = 1;
    while(y){
        if(y & 1) answ = answ * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return answ;
}

signed main(){

    int n, m;
    cin >> n >> m;
    string s; cin >> s;

    //cout << "s0 = " << s << '\n';
    int cnt = 0;
    while(s.size() < 4*m){
        cnt++;
        // cout << s << '\n';
        s = s.substr(0, s.size() / 2) + s + nextString(s.substr(s.size()/2, s.size() - (s.size() / 2) + 1));
        // if(i == 10) cout << "s" << i << ": " << s.substr(0, s.size() / 2) << " " << s << " " << nextString(s.substr(s.size()/2, s.size() - (s.size() / 2) + 1)) << '\n';
        // if(i == 10) cout << "size = " << snxt.size();
        // s = snxt;

    }
    // cout << cnt << '\n';
    // cout << s << '\n';
    string answ;
    // cout << cnt << '\n';
    int offset = (fexp(10, 100, 26) - cnt + 26) % 26;
    for(int i = s.size() - 1; i >= s.size() - m; i--){
        answ.push_back(((s[i] - 'a' + offset + 26)% 26) + 'a');
    }
    reverse(answ.begin(), answ.end());
    cout << answ << '\n';
    // cout << answ.size() << '\n';
    return 0;
}