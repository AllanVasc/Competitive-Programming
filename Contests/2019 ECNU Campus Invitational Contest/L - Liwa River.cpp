//L - Liwa River
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v(7,0);
ll answer;

void debug(int caso){

    cout << "Agrupei " << caso <<  '\n';
    for(int i = 1; i <= 6; i++){
        cout << v[i] << " ";
    }
    cout << '\n';
    cout << answer << '\n';
    cout << '\n';
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;

    while(n--){

        answer = 0;

        for(int i = 1; i <= 6; i++){
            cin >> v[i];
        }

        // Pegando os de 6 (não tem o que fazer)
        answer += v[6];
        v[6] -= v[6];

        //debug(6);

        // Agrupando 5
        answer += v[5];
        int minn = min(v[5], v[1]);
        v[1] -= minn;
        v[5] = 0;

        //debug(5);

        // Agrupando 4
        answer += v[4];
        if(v[4] > 0){

            if(v[2] >= v[4]){ //Da para fechar tudo bonitinho e ficar 2's sobrando
                v[2] -= v[4];
                v[4] = 0;
            }
            else{ //Vai sobrar v[4] ainda para poder completar
                v[4] -= v[2];
                v[2] = 0;
            }

            if(v[1] >= 2*v[4]){ //Da para fechar os de 4 com 1's bonitinho
                v[1] -= 2*v[4];
                v[4] = 0;
            }
            else{ //Não deu match mas n tem mais oq fazer
                v[1] = 0;
                v[4] = 0;
            }
        }

        //debug(4);

        // Agrupando 3
        answer += v[3]/2;
        v[3] = v[3]%2;

        //Sobrou no máximo 1 de v[3]
        if(v[3] == 1){
            answer++;
            v[3]--;
            
            if(v[2] >= 1 && v[1] >= 1){ // Posso completar com 2,1 ou 1,1,1
                v[2]--;
                v[1]--;
            }
            else if(v[1] >= 3){
                v[1] -= 3;
            }
            else{  //Não consigo completar!

                if(v[2]){ //Boto uma dupla só e fica faltando 1 vaga
                    v[2]--;
                }
                else{ // Se chegou aq é pq tem menos que 3, logo fica 0
                    v[1] = 0;
                }

            }
            // Não tem mais o que fazer
        }

        //debug(3);

        // Agrupando os de 2
        answer += v[2]/3;
        v[2] = v[2]%3;

        // Pode ter sobrado 2 ou 1 v[2]
        if(v[2] == 2){
            // junta esses 2 e ve se encaixa com de 1
            answer++;
            if(v[1] >= 2){
                v[1] -= 2;
                v[2] = 0;
            }
            else{ //Não tem como completar
                v[1] = 0;
                v[2] = 0;
            }
        }
        if(v[2] == 1){ // Só posso usar os de 1 para completar
            answer++;
            if(v[1] >= 4){
                v[1] -= 4;
                v[2] = 0;
            }
            else{
                v[1] = 0;
                v[2] = 0;
            }

        }

        //debug(2);

        // Agrupando de 1
        answer += v[1]/6;
        v[1] = v[1]%6;

        if(v[1]){ //Se ainda sobrar
            answer++;
            v[1] = 0;
        }

        //debug(1);
        
        cout << answer << '\n';
    }
   return 0;
}
