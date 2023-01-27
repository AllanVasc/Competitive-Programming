//B - Happy Line
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int qtd;
    cin >> qtd;
 
    priority_queue <int> pq;
    int answer[200100];
 
    for(int i = 0; i  < qtd; i++){
 
        int aux;
        cin >> aux;
 
        pq.push(aux-(qtd-1)+i);
 
    }
 
    for(int i = qtd-1; i>=0; i--){
 
        answer[i] = pq.top()+(qtd-1)-i;
        pq.pop();
 
        if( (i < qtd-1 && answer[i] > answer[i+1]) || answer[i] < 0){
            cout << ":(" << '\n';
            return 0;
        }
 
    }
 
    for(int i = 0; i < qtd-1; i++){
        cout << answer[i] << " ";
    }
 
    cout << answer[qtd-1] << '\n';
 
    return 0;
}
 
/*
 
 
*/