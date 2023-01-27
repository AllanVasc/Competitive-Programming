// D - Maximum Product Strikes Back
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;


int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
 
    cin >> t;
 
    while(t--){

        int n;

        cin >> n;

        vector<int> v;
        vector<int> zero_idx;
        
        v.push_back(0);
        for(int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            v.push_back(aux);

            if(aux == 0){
                zero_idx.push_back(i+1);
            }
        }
        v.push_back(0);
        zero_idx.push_back(n+1);

        ll maxQtd2 = 0;
        int l_answer = 0;
        int r_answer = n;

        int l_limite = 0;
        int r_limite = 0;

        while(zero_idx.size() != 0){
            
            r_limite = zero_idx[0];
            
            ll qtdAtual2 = 0;
            ll qtdNeg = 0;

            for(int i = l_limite+1; i < r_limite; i++){
                if(abs(v[i]) == 2) qtdAtual2++;
                if(v[i] < 0) qtdNeg++;
            }

            if(qtdAtual2 > 0 && qtdAtual2 > maxQtd2 && qtdNeg%2 == 0){ //Produto positivo
                maxQtd2 = qtdAtual2;
                l_answer = l_limite;
                r_answer = (n-r_limite + 1);
            }

            if(qtdNeg%2 == 1){  // Procurar negativo

                int idx_div;

                for(int i = l_limite+1; i < r_limite; i++){ // Analisa lado esquerdo
                    if(v[i] < 0){
                        idx_div = i;
                        break;
                    }
                }

                qtdAtual2 = 0;
                for(int i = l_limite+1; i < idx_div; i++){  // Analisa prefixo
                    if(abs(v[i]) == 2) qtdAtual2++;
                }

                if(qtdAtual2 > maxQtd2){
                    maxQtd2 = qtdAtual2;
                    l_answer = l_limite;
                    r_answer = (n-idx_div + 1);
                }
                
                qtdAtual2 = 0;
                for(int i = idx_div + 1; i < r_limite; i++){    // Analisa sufixo
                    if(abs(v[i]) == 2) qtdAtual2++;
                }

                if(qtdAtual2 > maxQtd2){
                    maxQtd2 = qtdAtual2;
                    l_answer = idx_div;
                    r_answer = (n-r_limite + 1);
                }

                for(int i = r_limite-1; i > l_limite; i--){ // Analisa lado direito
                    if(v[i] < 0){
                        idx_div = i;
                        break;
                    }
                }

                qtdAtual2 = 0;
                for(int i = l_limite+1; i < idx_div; i++){
                    if(abs(v[i]) == 2) qtdAtual2++;
                }

                if(qtdAtual2 > maxQtd2){
                    maxQtd2 = qtdAtual2;
                    l_answer = l_limite;
                    r_answer = (n-idx_div + 1);
                }

                qtdAtual2 = 0;
                for(int i = idx_div+1; i < r_limite; i++){
                    if(abs(v[i]) == 2) qtdAtual2++;
                }

                if(qtdAtual2 > maxQtd2){
                    maxQtd2 = qtdAtual2;
                    l_answer = idx_div;
                    r_answer = (n-r_limite + 1);
                }

            }

            l_limite = r_limite;
            zero_idx.erase(zero_idx.begin());
        }   

        cout << l_answer << " " << r_answer << '\n';
 
    }
 
    return 0;
}