#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("sieve.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        if(s2.size() > s1.size()) swap(s1, s2);
        vector<int> div;
        for(int i = 1; i * i <= s2.size(); i++){
            int n = s2.size();
            if(n % i == 0){
                div.push_back(i);
                if(n / i != i) div.push_back(n / i);
            }
        }

        // cout << "div = ";
        // for(auto x : div) cout << x << " ";
        // cout << '\n';

        int answ = 0;
        for(auto val : div){
            if(s1.size() % val != 0) continue;
            string check;
            for(int i = 0; i < val; i++) check += s2[i];
            bool dif = false;
            for(int i = 0; i < s1.size(); i++){
                if(s1[i] != check[i % val]) dif = true;
            }
            for(int i = 0; i < s2.size(); i++){
                if(s2[i] != check[i % val]) dif = true;
            }
            if(!dif){
                answ = max(answ, (int) check.size());
            }
        }
        cout << answ << '\n';
    }
    return 0;
}