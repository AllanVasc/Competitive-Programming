#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

char askLetter(int idx){
    cout << "? 1 " << idx << endl;
    char answ;
    cin >> answ;
    return answ;
}

int askRange(int l, int r){
    cout << "? 2 " << l << " " << r << endl;
    int answ;
    cin >> answ;
    return answ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    string answ = "";
    vector<vector<int>> diff(n + 1);
    for(int i = 0; i < n; i++){
        if(i == 0){
            answ.push_back(askLetter(i + 1));
            diff[i] = {1};
        }
        else{
            int query = askRange(1, i + 1);
            if(query > diff[i - 1][0]){
                answ.push_back(askLetter(i + 1));
            }
            else{
                map<char, int> lastPos;
                for(int j = 0; j < answ.size(); j++) lastPos[answ[j]] = j;
                vector<int> pos;
                for(auto x : lastPos) pos.push_back(x.second);
                sort(pos.begin(), pos.end());
                int l = 0;
                int r = pos.size();
                while(r - l > 1){
                    int mid = (l + r)/2;
                    int query = askRange(pos[mid] + 1, i + 1);
                    if(query == diff[i - 1][pos[mid]]) l = mid;
                    else r = mid;
                }
                answ.push_back(answ[pos[l]]);
            }
            diff[i].resize(i + 1);
            set<char> q;
            for(int j = i; j >= 0; j--){
                q.insert(answ[j]);
                diff[i][j] = q.size();
            }
       
        }
    }
    cout << "! " << answ << endl;
    return 0;
}