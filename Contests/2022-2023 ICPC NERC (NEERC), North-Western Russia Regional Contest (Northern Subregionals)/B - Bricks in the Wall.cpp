#include <bits/stdc++.h>

#define ii pair<int,int>
using namespace std;

const int ms = 1e6 + 10;

int seg[4*ms];


void upd(int pos, int val, int l, int r, int idx){
    if(l == r){
        seg[idx] += val;
        return;
    }
    int m = (l+r)/2;
    if(pos <= m) upd(pos, val, l, m, 2*idx +1);
    else upd(pos, val, m+1, r, 2*idx +2);

    seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
}


int qry(int l, int r, int idx){
    if(l == r) return l;
    int m = (l+r)/2;

    if(seg[2*idx + 2]) return qry(m+1, r, 2*idx +2);
    return qry(l, m, 2*idx +1);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<ii>> pe(n, vector<ii> (m, ii(-1, -1))), deita(n, vector<ii> (m, ii(-1, -1)));
        vector<vector<char> > grid(n, vector<char>(m));
        vector<int> aux;
        int R = max(n, m) + 1;
        // trocar o R da seg depois

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> grid[i][j];
            }
        }

        // pega os deitados
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int start = j;
                while(j < m && grid[i][j] == '.') j++;
                int sz = j - start;
                if(sz){
                    aux.push_back(sz);
                    upd(sz, 1, 0, R, 0);
                    for(int k=start; k<j; k++)deita[i][k] = ii(start, j-1);
                }
            }
        }

        // pega os caras em pe
        for(int j=0; j<m; j++){
            for(int i=0; i<n; i++){
                int start = i;
                while(i < n && grid[i][j] == '.') i++;
                int sz = i - start;
                if(sz){
                    aux.push_back(sz);
                    upd(sz, 1, 0, R, 0);
                    for(int k=start; k<i; k++) pe[k][j] = ii(start, i-1);
                }
            }
        }
        int ans =0;
        // testa para os caras deitados

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(deita[i][j].first == j){
                    int mx = 0;
                    upd(deita[i][j].second - deita[i][j].first + 1, -1, 0, R, 0);
                    vector<int> gone; // atualizar de volta na seg
                    for(int k= j; k<=deita[i][j].second; k++){
                        // ver se tem um cara em pe cruzando
                        if(pe[i][k] == ii(-1, -1)) continue;
                        // tira o tamanho dele na seg
                        gone.push_back(pe[i][k].second - pe[i][k].first +1);
                        upd(pe[i][k].second - pe[i][k].first +1, -1, 0, R, 0);
                        // ver os dois tamanhos dele
                        int up = i - pe[i][k].first;
                        int down = pe[i][k].second - i;
                        mx = max({mx, up, down});
                    }
                    mx = max(mx, qry(0, R, 0));

                    for(int x: gone) upd(x, 1, 0, R, 0);

                    upd(deita[i][j].second - deita[i][j].first + 1, 1, 0, R, 0);

                    ans = max(ans, mx + 1 +deita[i][j].second - deita[i][j].first);

                }
            }
        }
        // testa para os caras em pe
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pe[i][j].first == i){
                    int mx = 0;
                    upd(pe[i][j].second - pe[i][j].first + 1, -1, 0, R, 0);
                    vector<int> gone; // atualizar de volta na seg
                    for(int k= i; k<=pe[i][j].second; k++){
                        // ver se tem um cara deitad0 cruzando
                        if(deita[k][j] == ii(-1, -1)) continue;
                        // tira o tamanho dele na seg
                        gone.push_back(deita[k][j].second - deita[k][j].first +1);
                        upd(deita[k][j].second - deita[k][j].first +1, -1, 0, R, 0);
                        // ver os dois tamanhos dele
                        int left = j - deita[k][j].first;
                        int right =deita[k][j].second - j;
                        mx = max({mx, left, right});
                    }
                    mx = max(mx, qry(0, R, 0));

                    for(int x: gone) upd(x, 1, 0, R, 0);
                    upd(pe[i][j].second - pe[i][j].first + 1, 1, 0, R, 0);
                    ans = max(ans, mx + 1 +pe[i][j].second - pe[i][j].first);

                }
            }
        }


        cout << ans << '\n';

        // dar o update p o proximo caso
        for(int x : aux) upd(x, -1, 0, R, 0);


    }

}