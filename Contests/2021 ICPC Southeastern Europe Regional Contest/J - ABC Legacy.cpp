// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ii> answ;
    queue<int> q;

    int qtdA = 0;
    int qtdB = 0;
    int qtdC = 0;

    for(int i = 0; i < 2*n; i++){
        if(s[i] == 'C'){
            qtdC++;
            q.push(i);
        }
        else if(s[i] == 'A') qtdA++;
        else qtdB++;
    }

    vector<int> visited(2*n,0);
    int qtdBC = qtdB + qtdC - qtdA;

    if(qtdBC%2 == 1){
        cout << "NO" << '\n';
        return 0;
    }
    else qtdBC = qtdBC/2;

    for(int i = 0; i < 2*n && qtdBC; i++){
        if(s[i] == 'B'){
            while(!q.empty()){
                if(q.front() > i){
                    answ.push_back({i,q.front()});
                    visited[i] = 1;
                    visited[q.front()] = 1;
                    qtdBC--;
                    q.pop();
                    break;
                }
                else{
                    q.pop();
                }
            }
        }
    }

    while(!q.empty()) q.pop();

    for(int i = 0; i < 2*n; i++){
        if((s[i] == 'B' || s[i] == 'C') && visited[i] == 0){
            q.push(i);
        }
    }

    for(int i = 0; i < 2*n; i++){
        if(s[i] == 'A'){
            while(!q.empty()){
                if(q.front() > i){
                    answ.push_back({i, q.front()});
                    q.pop();
                    break;
                }
                else{
                    q.pop();
                }
            }
        }
    }

    if(answ.size() == n){
        cout << "YES" << '\n';
        for(int i = 0; i < answ.size(); i++){
            cout << answ[i].first+1 << " " << answ[i].second+1 << '\n';
        }
    }
    else{
        cout << "NO" << '\n';
    }

    return 0;
}