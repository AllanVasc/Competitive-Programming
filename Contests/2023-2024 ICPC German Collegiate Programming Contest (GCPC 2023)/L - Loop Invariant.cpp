#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s; cin >> s;
    int n = s.size();
    stack<char> st;
    string curr = "";
    vector<string> int_to_str(2e6, "");
    map<string, int> mp;
    vector<int> ordem;
    for(int i = 0; i < n; i++){
        curr.push_back(s[i]);
        if(s[i] == '('){
            st.push(s[i]);
        }
        else{
            st.pop();
            if(st.size() == 0){
                // balanced
                if(mp.count(curr) == 0){
                    mp[curr] = mp.size();
                }
                ordem.push_back(mp[curr]);
                int_to_str[mp[curr]] = curr;
                curr.clear();
            }
        }
    }
    int pos = -1;
    for(int i = 1; i < ordem.size(); i++){
        if(ordem[i] != ordem[0]){
            pos = i;
            break;
        }
    }
    // cout << "ordem:";
    // for(auto x : ordem) cout << x << " ";
    // cout << '\n';

    if(pos == -1){
        cout << "no" << '\n';
    }
    else{
        for(int i = pos; i < ordem.size(); i++){
            cout << int_to_str[ordem[i]];
        }
        for(int i = 0; i < pos; i++){
            cout << int_to_str[ordem[i]];
        }
        cout << '\n';
    }
    return 0;
}