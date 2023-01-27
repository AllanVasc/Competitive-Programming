#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<string, int> mp;
    vector<vector<int>> v;
    v.assign(1000 + 10, vector<int>(3,0));

    int qtd = 1;
    int total_meia = 0;
    for(int i = 0; i < n; i++){
        string s1,s2;
        int value;
        cin >> s1 >> s2 >> value;

        total_meia += value;

        if(mp[s1] == 0){
            mp[s1] = qtd;
            if(s2 == "left"){
                v[qtd][0] += value;
            }
            else if(s2 == "right"){
                v[qtd][1] += value;
            }
            else{
                v[qtd][2] += value;
            }
            
            qtd++;
        }
        else{
            int idx = mp[s1];
            if(s2 == "left"){
                v[idx][0] += value;
            }
            else if(s2 == "right"){
                v[idx][1] += value;
            }
            else{
                v[idx][2] += value;
            }
        }

    }

    // cout << "Debug: nome | L | R | A" << '\n';
    // for(int i = 1; i < qtd; i++){
    //     cout << i << " " << v[i][0] << " " << v[i][1] << " " << v[i][2] << '\n';
    // }

    int answ = 0;

    for(int i = 1; i < qtd; i++){
        int curr = max(v[i][0], v[i][1]);
        if(curr == 0){
            curr = min(1, v[i][2]);
        }
        answ += curr;
    }

    if(answ == total_meia) cout << "impossible" << '\n';
    else cout << answ + 1 << '\n';


    return 0;
}