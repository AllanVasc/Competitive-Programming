#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<vector<int>> bit;

vector<vector<int>> v;

void build(){
    bit.assign(v.size() + 1, vector<int>(v.size() + 1, 0));

    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v[i].size(); j++)
            bit[i+1][j+1] = v[i][j];

    for(int i = 1; i < bit.size(); i++){
        for(int j = 1; j < bit[i].size(); j++){
            int idx_i = i + (i & (-i));
            int idx_j = j + (j & (-j));
            if(idx_i < bit.size() && idx_j < bit[i].size())
                bit[idx_i][idx_j] += bit[i][j];
        }
    }
}

// Returns the sum of [0,0] to [i,j]
int query(int i, int x){
    int result = 0;
    for(++i; i > 0; i -= i & -i)
        for(int j = x+1; j > 0; j -= j & -j)
            result += bit[i][j];
    return result;
}

int range_query(int i_1, int j_1, int i_2, int j_2){
    return query(i_2,j_2) - query(i_1 - 1, j_2) - query(i_2, j_1 - 1) + query(i_1 - 1, j_1 - 1);
}

void update(int i, int x, int add){
    for(++i; i < bit.size(); i += i & -i)
        for(int j = x + 1; j < bit[i].size(); j += j & -j){
            bit[i][j] += add;
        }
}

void debug(int n){
    cout << "bit atual: " << '\n';
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < n + 1; j++){
            cout << bit[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        v.assign(n, vector<int>(n, 0));
        build();

        string command;
        cin >> command;
        while(command[0] != 'E'){

            if(command[1] == 'E'){  // SET
                int x, y, num;
                cin >> x >> y >> num;

                int curr = range_query(x, y, x, y);
                update(x, y, -curr + num);
                // debug(n);
            }
            else{   // Sum
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << range_query(x1, y1, x2, y2) << '\n';
            }

            cin >> command;
        }
        cout << '\n';
    }
    return 0;
}