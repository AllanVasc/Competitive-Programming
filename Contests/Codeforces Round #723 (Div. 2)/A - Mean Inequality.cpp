// A - Mean Inequality
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int qtdCasos;
    cin >> qtdCasos;
 
    while(qtdCasos--){
 
        int n;
        cin >> n;
        vector<int> v;
 
        for(int i = 0; i < 2*n; i++){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }
 
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
 
        vector<int>answer(2*n,0);
        int idx = 0;
        for(int i = 0; i < 2*n; i+=2){
            answer[i] = v[idx++];
        }
 
        for(int i = 1; i < 2*n; i+=2){
            answer[i] = v[idx++];
        }
 
        for(int i = 0; i < 2*n; i++){
            if(i + 1 != 2*n)
                cout << answer[i] << " ";
            else
                cout << answer[i] << '\n';
        }
    }
 
}
 
/*
 
 
*/