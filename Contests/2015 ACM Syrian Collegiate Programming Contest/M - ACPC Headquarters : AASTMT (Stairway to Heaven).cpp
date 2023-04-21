#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<tuple<string,int,int,set<string>> > data;
        for(int i = 0; i < n; i++){
            string name;
            int start, end, qtd;
            cin >> name >> start >> end >> qtd;
            set<string> aux;
            for(int j = 0; j < qtd; j++){
                string s;
                cin >> s;
                aux.insert(s);
            }
            data.emplace_back(name, start, end, aux);
        }

        set<string> conflicts;
        for(int i = 0; i < n; i++){
            auto[n1, s1, e1, conj1] = data[i];
            
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                auto [n2, s2,en2, conj2] = data[j];
                if(n1 == n2) continue;
                
                if(s2 >= s1 && s2 <= e1){

                    for(auto x : conj1){
                        if(conj2.count(x)){
                            conflicts.insert(x);
                        }
                    }

                }


            }
        }

        cout << conflicts.size() << '\n';
        for(auto x : conflicts) cout << x << '\n';
    }
    return 0;
}