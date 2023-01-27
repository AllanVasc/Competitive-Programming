// J - Saeed and Folan
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

        ll l1,r1,p1,d1;
        ll l2,r2,p2,d2;
        ll k;

        cin >> l1 >> r1 >> p1 >> d1;
        cin >> l2 >> r2 >> p2 >> d2;
        cin >> k;

        ll atual1,atual2;

        atual1 = p1;
        atual2 = p2;   

        ll answer = 0;

        for(int i = 0; i < k; i++){
            
            if(d1 == 0){
                if(atual1 == l1){
                    d1 = 1;
                    atual1++;
                }
                else{
                    atual1--;
                }
            }
            else{ //d1 == 1
                if(atual1 == r1){
                    d1 = 0;
                    atual1--;
                }
                else{
                    atual1++;
                }

            }

            if(d2 == 0){
                if(atual2 == l2){
                    d2 = 1;
                    atual2++;
                }
                else{
                    atual2--;
                }
            }
            else{
                
                if(atual2 == r2){
                    d2 = 0;
                    atual2--;
                }
                else{
                    atual2++;
                }
            }

            if(atual1 == atual2){
                answer++;
            }
        }

        cout << answer << '\n';

    }
    return 0;
}
 
/*

 
*/