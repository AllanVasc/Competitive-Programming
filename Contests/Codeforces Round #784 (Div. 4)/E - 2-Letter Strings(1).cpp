// E - 2-Letter Strings
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;


int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
 
    while(t--){

        int n;

        cin >> n;

        vector<string> v;
        map<string,ll> freq_word;
        map<char,ll> freq_init;
        map<char,ll> freq_fin;

        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            v.push_back(s);
        }
        
        ll answ = 0;

        for(int i = 0; i < n; i++){
            string s = v[i];
            
            answ += freq_init[s[0]];
            answ += freq_fin[s[1]];
            answ -= 2*freq_word[s];

            freq_word[s]++;
            freq_init[s[0]]++;
            freq_fin[s[1]]++;
        }

        cout << answ << '\n';
    }
 
    return 0;
}