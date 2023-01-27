// C - Help Shahhoud
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
 
        string a,b;
        
        cin >> a >> b;
 
        bool check = true;
 
        int n = a.size();
 
        for(int i = 0, j = n-1; i <= n/2; i++, j--){
            
            string aux1 = a[i] + "" + a[j];
            string aux2 = b[i] + "" + b[j];
            
            sort(aux1.begin(),aux1.end());
            sort(aux2.begin(),aux2.end());
 
            if(aux1 != aux2){
                check = false;
            }
        }
 
        if(check == false){
            cout << -1 << '\n'; 
        }
        else{
 
            int answer = 0;
 
            int qtdInversao = 0;
            
            bool checkArray[n];
 
            for(int i = 0; i <= n/2; i++){
                
                if(a[i] != b[i]){
                    checkArray[i] = 0;
                }
                else{
                    checkArray[i] = 1;
                }
                //cout << checkArray[i] << ' ';
            }
            //cout << '\n';
 
            for(int i = 0, j = n-1; i < n/2; i++, j--){
                
                if(a[i] != a[j]){ // preciso olhar check
 
                    if(qtdInversao%2 == 0){
                        checkArray[i] = checkArray[i];
                    }
                    else{
                        checkArray[i] = 1 - checkArray[i];
                    }
                    if(checkArray[i] == 0){
                        //cout << "Posicao " << i << " deu diferente!" << '\n';
                        answer++;
                        qtdInversao++;
                    }
                }
                // se nao ja ta igual e faz nada
            }
 
            cout << answer << '\n';
 
        }
    }
    return 0;
}
 
/*
 
 
*/