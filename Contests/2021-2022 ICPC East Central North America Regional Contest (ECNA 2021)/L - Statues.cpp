#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> ord_statues;
vector<multiset<int>> diagonals;
int answ = INF;

void checkDiff(){
    int ptr = 0;
    int diff = 0;
    for(int i = 0; i < diagonals.size(); i++){
        multiset<int> curr = diagonals[i];
        multiset<int> smallest;
        for(int j = 0; j < curr.size(); j++){
            smallest.insert(ord_statues[ptr]);
            ptr++;
        }

        // cout << "na diagonal: ";
        // for(auto x : curr) cout << x << " ";
        // cout << '\n';
        // cout << "na smallest: ";
        // for(auto x : smallest) cout << x << " ";
        // cout << '\n';

        for(auto x : curr){
            if(smallest.count(x) == 0){
                diff++;
            }
            else{
                smallest.erase(smallest.find(x));
            }
        }
    }
    answ = min(answ, diff);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
            if(mat[i][j] != -1) ord_statues.push_back(mat[i][j]);
        }
    }

    sort(ord_statues.begin(), ord_statues.end());

    // Sentido "B" 
    for(int i = 0; i < n; i++){
        multiset<int> curr;
        for(int j = i, k = 0; j >= 0 && k < m; j--, k++){
            if(mat[j][k] != -1) curr.insert(mat[j][k]);
        }
        diagonals.push_back(curr);
    }
    for(int j = 1; j < m; j++){
        multiset<int> curr;
        for(int i = n - 1, k = j; k < m && i >= 0; i--, k++){
            if(mat[i][k] != -1) curr.insert(mat[i][k]);
        }
        diagonals.push_back(curr);
    }
    // cout << "answ = " << answ << "\n";
    checkDiff();
    reverse(diagonals.begin(), diagonals.end());
    checkDiff();

    diagonals.clear();

    // Sentido "C"
    for(int j = 0; j < m; j++){
        multiset<int> curr;
        for(int i = n - 1, k = j; k >= 0 && i >= 0; i--, k--){
            if(mat[i][k] != -1) curr.insert(mat[i][k]);
        }
        diagonals.push_back(curr);
    }
    for(int i = n - 2; i >= 0; i--){
        multiset<int> curr;
        for(int j = i, k = m - 1; k >= 0 && j >= 0; j--, k--){
            if(mat[j][k] != -1) curr.insert(mat[j][k]);
        }
        diagonals.push_back(curr);
    }

    checkDiff();
    reverse(diagonals.begin(), diagonals.end());
    checkDiff();


    cout << answ << '\n';
    return 0;
}