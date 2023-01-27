#include <bits/stdc++.h>
using namespace std;
  
// #define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

const int MAXW = 1e9 + 10;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    set<pair<int,int>> available;
    map<int, int> id_to_w;
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        available.insert({w, i+1});
        id_to_w[i+1] = w;
    }

    while(q--){

        char command;
        cin >> command;

        if(command == '+'){
            int w, id;
            cin >> w >> id;
            available.insert({w, id});
            id_to_w[id] = w;
        }
        else if(command == '-'){
            int id;
            cin >> id;
            available.erase({id_to_w[id], id});
        }
        else{ // Query

            int id;
            cin >> id;
            int curr_w = id_to_w[id];
            
            // cout << "disponivel: ";
            // for(auto i : available){
            //     cout << "(" << i.first << "," << i.second << ")"; 
            // }
            // cout << '\n';

            // cout << "check: " << "(" << curr_w  << "," << id<< ")\n"; 

            auto temp = *(available.begin());
            int answ = 1;
            int prefix_sum = temp.first;
            
            available.erase(available.begin());

            while(1){ // Anteriores de "curr_w"

                pair<int,int> check = {prefix_sum, 0};
                auto itr = available.lower_bound(check);
                if(itr == available.end() || (prefix_sum + itr->first) > curr_w ) break;

                prefix_sum += itr->first;
                answ++;
            }
            if(temp != make_pair(curr_w, id)){
                prefix_sum += curr_w;
                answ++;
            }
            while(1){ // Anteriores de "curr_w"

                pair<int,int> check = {prefix_sum, 0};
                auto itr = available.lower_bound(check);
                if(itr == available.end()) break;

                prefix_sum += (*itr).first;
                answ++;
            }

            available.insert(temp);

            cout << answ << '\n';
        }
    }
    return 0;
}