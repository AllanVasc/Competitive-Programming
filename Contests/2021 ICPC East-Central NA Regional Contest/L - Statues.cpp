// L - Statues
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> n >> m;

    vector<vector<int>> matrix;
    matrix.assign(n,vector<int>());

    map<int, set<int>> dig1;
    map<int, set<int>> dig2;
    vector<int> v;
    for(int i = 0; i < n; i++){
        matrix[i].assign(m,-1);
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] != -1){
                dig1[i+j].insert(matrix[i][j]);
                dig2[i-j].insert(matrix[i][j]);
                v.push_back(matrix[i][j]);
            }
        }
    }
    sort(v.begin(), v.end());

    int answ = LONG_LONG_MAX;

    int idx = 0;
    set<int> moved;
    for(auto key: dig1){
        for(int i = 0; i < key.second.size(); i++){
            if(key.second.find(v[idx]) == key.second.end()){
                moved.insert(v[idx]);
            }
            idx++;
        }
    }
    answ = min(answ, (int)moved.size());
    idx--;
    moved.clear();
    for(auto key: dig1){
        for(int i = 0; i < key.second.size(); i++){
            if(key.second.find(v[idx]) == key.second.end()){
                moved.insert(v[idx]);
            }
            idx--;
        }
    }
    answ = min(answ, (int)moved.size());
    idx = 0;
    moved.clear();
    for(auto key: dig2){
        for(int i = 0; i < key.second.size(); i++){
            if(key.second.find(v[idx]) == key.second.end()){
                moved.insert(v[idx]);
            }
            idx++;
        }
    }
    answ = min(answ, (int)moved.size());
    idx--;
    moved.clear();
    for(auto key: dig2){
        for(int i = 0; i < key.second.size(); i++){
            if(key.second.find(v[idx]) == key.second.end()){
                moved.insert(v[idx]);
            }
            idx--;
        }
    }
    answ = min(answ, (int)moved.size());

    cout << answ << '\n';
    return 0;
}