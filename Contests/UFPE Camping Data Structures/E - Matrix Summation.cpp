//  E - Matrix Summation
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

vector<vector<int>> bit;

vector<vector<int>> v;

void build(){
    bit.assign(v.size()+1, vector<int>(v.size()+1, 0));

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

int query(int i, int x){
    int result = 0;
    for(++i; i > 0; i -= i & -i)
        for(int j = x+1; j > 0; j -= j & -j)
            result += bit[i][j];
    return result;
}

int range_query(int i_1, int j_1, int i_2, int j_2){
    return query(i_2,j_2) - query(i_1-1,j_2) - query(i_2,j_1-1) + query(i_1-1,j_1-1);
}

void update(int i, int x, int add){
    int aux = add;
    add = add - v[i][x];
    v[i][x] = aux;

    for(++i; i < bit.size(); i += i & -i)
        for(int j = x+1; j < bit[i].size(); j += j & -j)
            bit[i][j] += add;
}

void print_bit(){

    cout << "BIT:\n";
    for(int i = 0; i < bit.size(); i++){
        for(int j = 0; j < bit[i].size(); j++)
            cout << bit[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        v.assign(n, vector<int>());
        for(int i = 0; i < n; i++) v[i].assign(n, 0);
        build();

        string op;
        cin >> op;    
        while(op != "END"){
            if(op == "SET"){
                int x,y,num;
                cin >> x >> y >> num;
                update(x,y,num);
            }
            else if(op == "SUM"){
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                // cout << query(x2,y2) << '\n';
                cout << range_query(x1,y1,x2,y2) << '\n';
            }
            cin >> op;
        }
    }
    return 0;
}
