#include<bits/stdc++.h>

using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        string s, ans;
        cin >> s;

        vector <pair <char, int>> aux;
        char last = s[0];
        int cnt = 1;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == last){
                cnt++;
            }
            else{
                aux.emplace_back(last, cnt);
                last = s[i];
                cnt = 1;
            }
        }

        aux.emplace_back(last, cnt);

        for(auto i:aux){
            for(int j = 0; j < max(2, i.second); j++){
                ans.push_back(i.first);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}