#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<set<int>> v;
    v.assign(n, set<int>());

    vector<int> closest_friend(n, 0);

    map<int, map<int,int>> hash;

    for(int i = 0; i < n; i++){
        int qtd_cursos;
        cin >> qtd_cursos;
        for(int j = 0; j < qtd_cursos; j++){
            int curso, grade;
            cin >> curso >> grade;
            v[i].insert(curso);
            hash[i][curso] = grade;
        }
    }

    // for(int i = 0; i < n; i++){
    //     cout << "cursos de " << i+1 << '\n';
    //     for(auto c : v[i]){
    //         cout << c << " nota = " << hash[i][c] << '\n';
    //     }
    // }

    for(int i = 0; i < n; i++){ // Pega mais proximo
        int close = LONG_LONG_MAX;
        int idx = 0;

        for(int j = 0; j < n; j++){
            if(i == j) continue;
            int distance = 0;
            bool check = false;

            for(auto cursos : v[i]){
                if(v[j].count(cursos) != 0){
                    distance += abs(hash[i][cursos] - hash[j][cursos])*abs(hash[i][cursos] - hash[j][cursos]);
                    check = true;
                }
            }

            if(close > distance && check){   // se for igual pega o de menor indice
                close = distance;
                idx = j;
            }
        }

        closest_friend[i] = idx;
    }

    // cout << "closes: " << '\n';
    // for(int i = 0; i < n; i++){
    //     cout << i+1 << " = " << closest_friend[i]+1 << '\n';
    // }

    for(int i = 0; i < n; i++){
        int answ = -1;
        int h_grade = -1;
        for(auto cursos : v[closest_friend[i]]){
            if(v[i].count(cursos) == 0){
                if(h_grade < hash[closest_friend[i]][cursos]){
                    answ = cursos;
                    h_grade = hash[closest_friend[i]][cursos];
                }
            }
        }
        cout << answ << '\n';
    }

    return 0;
}