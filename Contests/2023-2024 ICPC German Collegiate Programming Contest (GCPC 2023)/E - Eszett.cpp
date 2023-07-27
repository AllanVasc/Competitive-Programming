#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    vector <string> ans(1);
    string s;
    cin >> s;

    for(auto i:s) ans[0].push_back(tolower(i));

    for(int i = 1; i < ans[0].size(); i++){
        if(ans[0][i] == 's' && ans[0][i-1] == 's'){
            string aux = ans[0].substr(0, i - 1);
            aux += "B";
            aux += ans[0].substr(i + 1, ans[0].size() - (i + 1));
            // cout << aux << "\n";
            ans.push_back(aux);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for(auto &i:ans){
        cout << i << "\n";
    }

}