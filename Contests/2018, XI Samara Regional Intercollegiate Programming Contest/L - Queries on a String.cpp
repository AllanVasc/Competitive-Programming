// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<vector<int>> pos;

    pos.assign(26, vector<int>());
    for(int i = 0; i < s.size(); i++){
        pos[s[i]-'a'].push_back(i);
    }

    int q;
    cin >> q;

    string p = "";
    vector<int> idx_p;
    idx_p.push_back(-1);

    for(int i = 0; i < q; i++){
        string command;
        cin >> command;

        // cout << "string p = "  << p << '\n';
        // cout << "idx = ";
        // for(int j = 0; j < idx_p.size(); j++){
        //     cout << idx_p[j] << " ";
        // }
        // cout << '\n';

        if(command == "push"){
            char letter;
            cin >> letter;

            // cout << "vou add: " << letter << '\n';

            auto itr = upper_bound(pos[letter-'a'].begin(), pos[letter-'a'].end(), idx_p.back());

            if(itr != pos[letter-'a'].end()){
                p.push_back(letter);
                idx_p.push_back(*itr);

                cout << "YES" << '\n';
            }
            else{
                p.push_back(letter);
                idx_p.push_back(s.size()+5);

                cout << "NO" << '\n';
            }
        }
        else{

            p.pop_back();
            idx_p.pop_back();

            if((int) idx_p.back() <= (int) s.size()){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }

        }
    }
    return 0;
}