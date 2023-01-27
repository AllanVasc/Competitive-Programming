#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
    int n;
    cin >> n;
 
    map<int, string> id_to_name;
    vector<tuple<int,int,int>> v;
    for(int i = 0; i < n; i++){
        string name;
        int hp, at, df;
        cin >> name >> hp >> at >> df;
        id_to_name[i] = name;
        v.push_back({hp, at, df});
    }
 
    set<tuple<int,int,int>> answ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                
                if(i == j) continue;
                if(i == k) continue;
                if(j == k) continue;
 
                int hp_a = get<0>(v[i]);
                int at_a = get<1>(v[i]);
                int df_a = get<2>(v[i]);
 
                int hp_b = get<0>(v[j]);
                int at_b = get<1>(v[j]);
                int df_b = get<2>(v[j]);
 
                int hp_c = get<0>(v[k]);
                int at_c = get<1>(v[k]);
                int df_c = get<2>(v[k]);
                
                // A ganha de B;
                if(at_a - df_b <= 0) continue;
                int rounds = (hp_b + at_a - df_b - 1) / (at_a - df_b);
                int dano_em_a = rounds*(at_b - df_a);
                if(hp_a - dano_em_a <= 0) continue;
 
                // B ganha de C;
                if(at_b - df_c <= 0) continue;
                rounds = (hp_c + at_b - df_c - 1 ) / (at_b - df_c);
                int dano_em_b = rounds*(at_c - df_b);
                if(hp_b - dano_em_b <= 0) continue;
 
                // C ganha de A;
                if(at_c - df_a <= 0) continue;
                rounds = (hp_a + at_c - df_a - 1) / (at_c - df_a);
                int dano_em_c = rounds*(at_a - df_c);
                if(hp_c - dano_em_c <= 0) continue;
 
                vector<int> aux;
                aux.push_back(i);
                aux.push_back(j);
                aux.push_back(k);
                sort(aux.begin(), aux.end());
                
                answ.insert({aux[0], aux[1], aux[2]});
            }
        }
    }
 
    cout << answ.size() << '\n';
    for(auto i : answ){
        int id1 = get<0>(i);
        int id2 = get<1>(i);
        int id3 = get<2>(i);
 
        cout << id_to_name[id1] << " " << id_to_name[id2] << " " << id_to_name[id3] << '\n';
    }
 
    return 0;
}