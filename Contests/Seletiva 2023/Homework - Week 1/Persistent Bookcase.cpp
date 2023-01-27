#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353 ;

const int ms = 1e3 + 10;
vector<vector<bool>> persistent;
vector<vector<int>> tree;
vector<int> answ;
map<int, iii> information;
int qtd_books = 0;

void apply(int command, int i, int j, bool & ignore){
    if(command == 1){
        if(persistent[i][j] == true) return;
        qtd_books++;
        persistent[i][j] = true;
        ignore = false;
    }
    else if(command == 2){
        if(persistent[i][j] == false) return;
        qtd_books--;
        persistent[i][j] = false;
        ignore = false;
    }
    else if(command == 3){
        for(int k = 0; k < persistent[i].size(); k++){
            if(persistent[i][k] == true) qtd_books--;
            else qtd_books++;

            persistent[i][k] = !persistent[i][k];
        }
        ignore = false;
    }
    else{
        return;
    }
}

void desapply(int command, int i, int j, bool ignore){
    if(ignore) return;
    if(command == 1){
        if(persistent[i][j] == false) return;
        qtd_books--;
        persistent[i][j] = false;
    }
    else if(command == 2){
        if(persistent[i][j] == true) return;
        qtd_books++;
        persistent[i][j] = true;
    }
    else if(command == 3){
        for(int k = 0; k < persistent[i].size(); k++){
            if(persistent[i][k] == true) qtd_books--;
            else qtd_books++;

            persistent[i][k] = !persistent[i][k];
        }
    }
    else{
        return;
    }
}

void dfs(int u){
    auto [command, i, j] = information[u];
    bool ignore = true;
    apply(command, i, j, ignore);
    answ[u] = qtd_books;

    // cout << "estado: " << u << '\n';
    // cout << "answ = " << qtd_books << '\n';
    // cout << command << " " << i << " " << j << '\n';

    for(auto v : tree[u]){
        dfs(v);
    }
    desapply(command, i, j, ignore);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;

    tree.assign(1e5 + 10, vector<int>());
    int state = 0;
    for(int i = 0; i < q; i++){
        int command;
        cin >> command;
        if(command == 1 || command == 2){
            int i, j;
            cin >> i >> j;
            i--, j--;
            information[state + 1] = {command, i, j};
            tree[state].push_back(state + 1);
            state++;
        }
        else if(command == 3){
            int line;
            cin >> line;
            line--;
            information[state + 1] = {command, line, -1};
            tree[state].push_back(state + 1);
            state++;
        }
        else if(command == 4){
            int new_State;
            cin >> new_State;
            information[state + 1] = {-1, -1, -1};
            tree[new_State].push_back(state + 1);
            state++;
        }
    }

    answ.assign(state + 1, 0);
    persistent.assign(n, vector<bool>(m, false));

    dfs(0);

    for(int i = 1; i <= q; i++){
        cout << answ[i] << '\n';
    }

    return 0;
}