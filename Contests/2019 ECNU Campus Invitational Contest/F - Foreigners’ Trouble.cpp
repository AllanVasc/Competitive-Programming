// F. Foreigners’ Trouble
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
map<string,ll> mapa;
 
int main(){ 
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin >> n;
    cin.ignore();
 
    for(int i = 0; i < n; i++){
 
        string input,aux;
        getline(cin, input);
        bool espaco = false;
 
        for(int j = 0; j < input.size(); j++){
            
            if(j == 0){
                aux += input[j];
            }
            if(input[j] == ' ')
                espaco = true;
            else if (espaco == true && input[j] != ' '){
                espaco = false;
                aux += input[j];
            }
        }
 
        mapa[aux]++;
        //cout << aux << endl;
    }
 
    ll answer = 0;
 
    for(auto i : mapa){
        if(i.second > 0){
            answer += (i.second * (i.second-1))/2;
        }
    }
 
    cout << answer << '\n';
 
    return 0;
}
 
 
/*
 
 
*/