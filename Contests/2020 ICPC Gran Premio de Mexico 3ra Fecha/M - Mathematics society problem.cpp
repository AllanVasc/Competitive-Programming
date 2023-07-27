#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

const int mod = 1e9 + 7;
const int ms = 1e6 + 5;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    vector<int> num, cnt(10, 0);
    vector<vector<int> > id(10);
    for(int i=0; i<s.size(); i++){
        num.push_back(s[i] - '0');
        id[s[i]-'0'].push_back(i);
        cnt[s[i] - '0']++;
    }
    for(int i=1; i<=9; i++) reverse(id[i].begin(), id[i].end());

    vector<int> freq(10), need(10);
    int sum =0;
    for(int i=1; i<=9; i++){
        cin >> freq[i];
        sum += freq[i];
        need[i] = cnt[i] - freq[i];
    }



    vector<vector<int> > suf(10, vector<int> (num.size() + 1, 0));

    for(int i=num.size()-1; i>=0; i--){
        for(int j=1; j<=9; j++){
            suf[j][i] = suf[j][i+1] + (num[i] == j);
        }
    }

    int l = 0;
    vector<int> ans;
    for(int i=0; i<num.size() - sum; i++){
        
        for(int j=9;j>=1; j--){
            if(need[j] == 0) continue;
            bool check = true;
            int idx = id[j].back();
            for(int k=1; k<=9; k++){
                if(suf[k][idx] < need[k]) check = false;
            }
            if(check){
                l = idx;
                need[j]--;
                ans.push_back(j);
                break;
            }
        }
        for(int j=1; j<=9; j++){
            while(!id[j].empty() && id[j].back() <= l) id[j].pop_back();
        }
    }

    
    for(int i=0; i<ans.size(); i++) cout << ans[i];
    cout << endl;
    return 0;
}
