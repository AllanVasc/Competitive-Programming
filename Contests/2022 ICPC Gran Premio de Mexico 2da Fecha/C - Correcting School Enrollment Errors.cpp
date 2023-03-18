#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> allIds;
    map<int, set<int>> askeds;
    for(int i = 0; i < n; i++){
        int id, qtd;
        cin >> id >> qtd;
        allIds.insert(id);
        for(int j = 0; j < qtd; j++){
            int aux;
            cin >> aux;
            askeds[id].insert(aux);
        }
    }

    map<int, set<int>> received;
    for(int i = 0; i < m; i++){
        int id, qtd;
        cin >> id >> qtd;
        allIds.insert(id);
        for(int j = 0; j < qtd; j++){
            int aux;
            cin >> aux;
            received[id].insert(aux);
        }
    }

    map<int, set<ii>> answ;
    for(auto cur_id : allIds){
        for(auto pedi : askeds[cur_id]){
            if(received[cur_id].count(pedi) == 0){
                answ[cur_id].insert({pedi, 1});
            }
        }
        for(auto recebi : received[cur_id]){
            if(askeds[cur_id].count(recebi) == 0){
                answ[cur_id].insert({recebi, 0});
            }
        }
    }

    if(answ.size() == 0){
        cout << "GREAT WORK! NO MISTAKES FOUND!" << '\n';
    }
    else{
        int total = answ.size();
        int not_r = 0, missed = 0;
        for(auto cur_id : answ){
            cout << cur_id.first << " ";
            for(auto [val, flag] : cur_id.second){
                if(flag){
                    cout << "+" << val << " ";
                    missed++;
                }
                else{
                    cout << "-" << val << " ";
                    not_r++;
                }
            }
            cout << '\n';
        }
        cout << "MISTAKES IN " << total << " STUDENTS: " << not_r << " NOT REQUESTED, " << missed << " MISSED" << '\n';
    }

    return 0;
}