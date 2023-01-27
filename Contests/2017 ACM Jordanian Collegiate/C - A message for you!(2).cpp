//C. A message for you!
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    freopen("scoreboard.in", "r", stdin);
 
    int qtdCasos;
    
    cin >> qtdCasos;
 
    while(qtdCasos--){
 
        int qtdQuestions;
        string questionsMake;
        vector<pair<int,int>> scoreBoard;
        bool check[13];
 
        memset(check, false, sizeof(check));
 
        cin >> qtdQuestions >> questionsMake;
 
        for(int i = 0; i < qtdQuestions; i++){
            check[questionsMake[i]-'A'] = true;
        }
 
        for(int i = 0; i < 13; i++){
 
            int aux;
            cin >> aux;
 
            scoreBoard.emplace_back(aux,i);
 
        }
 
        sort(scoreBoard.begin(), scoreBoard.end());
 
        for(int i = 12; i >= 0; i--){
 
            if(!check[scoreBoard[i].second]){
                cout <<  char(scoreBoard[i].second + 'A') << '\n';
                break;
            }
 
        }
    }
 
}
 
/*
 
 
*/