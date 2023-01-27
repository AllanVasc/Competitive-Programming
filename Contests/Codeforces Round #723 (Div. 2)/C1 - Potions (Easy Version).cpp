// C1 - Potions (Easy Version)
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    
    ll vida = 0;
    ll answer = 0;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){

        vida += v[i];
        answer++;
        if(v[i] < 0){
            pq.push(abs(v[i]));
        }

        if(vida < 0){
            answer--;
            vida += pq.top();
            pq.pop();
        }

    }

    cout << answer << '\n';

    return 0;
}
 
/*
 
 
*/