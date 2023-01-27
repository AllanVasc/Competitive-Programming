// B - Battle Simulation 
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    map<char,char> mapa;

    mapa['R'] = 'S';
    mapa['B'] = 'K';
    mapa['L'] = 'H';

    string answ;

    for(int i = 0; i < s.size(); i++){

        if(i + 2 < s.size()){

            string aux = s.substr(i,3);

            if(aux == "RBL"){
                answ.push_back('C');
                i+=2;
            }
            else if(aux == "RLB"){
                answ.push_back('C');
                i+=2;
            }
            else if(aux == "BRL"){
                answ.push_back('C');
                i+=2;
            }
            else if(aux == "BLR"){
                answ.push_back('C');
                i+=2;
            }
            else if(aux == "LBR"){
                answ.push_back('C');
                i+=2;
            }
            else if (aux == "LRB"){
                answ.push_back('C');
                i+=2;
            }
            else
                answ.push_back(mapa[s[i]]);
        }
        else
            answ.push_back(mapa[s[i]]);
    }

    for(int i = 0; i < answ.size(); i++){
        cout << answ[i];
    }
    cout << '\n';
    return 0;
}
