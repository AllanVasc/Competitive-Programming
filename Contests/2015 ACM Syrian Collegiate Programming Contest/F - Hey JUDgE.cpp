#include<bits/stdc++.h>
using namespace std;

#define int long long
bool answ = false;

void backtrack(vector<int>& v, set<int>& conj){
    if(conj.size() == 5){
        // cout << "conj = ";
        // for(auto x : conj){
        //     cout << x << " ";
        // }
        // cout << '\n';
        answ = true;
        return;
    }
    for(int i = 0; i < v.size(); i++){
        int cur = v[i];
        if(conj.count(cur) == 0){
            conj.insert(cur);
            v.erase(v.begin() + i);
            backtrack(v, conj);
            
            v.push_back(cur);
            sort(v.begin(), v.end());
            conj.erase(cur);
        }

        for(int j = i + 1; j < v.size(); j++){
            int cur_2 = v[j];
            int sum = cur + cur_2;
            if(sum <= 5 && conj.count(sum) == 0){
                
                conj.insert(sum);
                v.erase(v.begin() + j);
                v.erase(v.begin() + i);
                
                backtrack(v, conj);
                v.push_back(cur);
                v.push_back(cur_2);
                sort(v.begin(), v.end());
                conj.erase(sum);
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        answ = false;
        string s;
        cin >> s;
        vector<int> v;
        for(int i = 0; i < s.size(); i++){
            v.push_back(s[i] - 'A' + 1);
        }

        set<int> conj;
        sort(v.begin(), v.end());
        backtrack(v, conj);

        if(answ){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}