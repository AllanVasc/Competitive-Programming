#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename T = int>
struct Hungarian{
    vector<vector<T>> a; // Matrix
    vector<T> u, v; // Potentials
    vector<int> p, way;
    int n, m;
    T inf;

    Hungarian(vector<vector<T>> & mat){
        n = mat.size();
        m = mat[0].size();
        a.assign(n + 1, vector<T>(m + 1, 0));
        u.assign(n + 1, 0);
        v.assign(m + 1, 0);
        p.assign(m + 1, 0);
        way.assign(m + 1, 0);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i + 1][j + 1] = mat[i][j];
        inf = numeric_limits<T>::max();
    }

    // Returns {min assignment, v} 
    // v[i] = Chosen column of the i-th row
    pair<T, vector<int>> assignment(){
        for(int i = 1; i<= n; i++){
            p[0] = i;
            int j0 = 0;
            vector<int> minv(m + 1, inf);
            vector<bool> used(m + 1, false);
            do{
                used[j0] = true;
                int i0 = p[j0], j1 = -1;
                T delta = inf;
                for(int j = 1; j <= m; j++) if(!used[j]){
                    T cur = a[i0][j] - u[i0] - v[j];
                    if(cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta) delta = minv[j], j1 = j;
                }
                for(int j = 0; j <= m; j++){
                    if(used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                }
                j0 = j1;
            } while(p[j0] != 0);
            do{
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while(j0);
        }
        vector<int> answ(n + 1); // answ[1.. n]
        for(int j = 1; j <= m; j++) answ[p[j]] = j; // column in 1-based
        return make_pair(-v[0], answ);
    }
};

signed main(){
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }
    
    Hungarian hungaro(v);
    auto answ = hungaro.assignment();
    cout << answ.first << endl;
    for(int i = 1; i < answ.second.size(); i++){
        cout << answ.second[i] - 1 << " ";
    }
    cout << '\n';
    return 0;
}

/*

Time Complexity:

assignment  -> O(n^2 * m)

Links:

https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
https://e--maxx-ru.translate.goog/algo/assignment_hungary?_x_tr_sch=http&_x_tr_sl=ru&_x_tr_tl=en&_x_tr_hl=ru

*/