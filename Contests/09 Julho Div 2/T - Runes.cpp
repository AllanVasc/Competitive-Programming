//  T - Runes
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18; 
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
 
    while(t--){
 
        string s;
        cin >> s;
        bool answ = false;
 
        set<int> not_possible;
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])) not_possible.insert(s[i] - '0');
        }
 
        for(int i = 0; i < 10; i++){
            
            if(not_possible.find(i) == not_possible.end()){
 
                // Number 1
                bool inv1 = false;
                int idx_op = -1;
                int number1 = 0;
                int qtd_dgt_1 = 0;
                for(int j = 0; j < s.size(); j++){
                    if(inv1 == false && s[0] == '-') inv1 = true;
                    else if(s[j] == '-' || s[j] == '+' || s[j] == '*'){
                        idx_op = j;
                        break;
                    }
                    else if(s[j] == '?'){
                        number1 = number1*10 + i;
                        qtd_dgt_1++; 
                    }
                    else{
                        number1 = number1*10 + s[j] - '0';
                        qtd_dgt_1++;
                    }
                }
                if(inv1) number1 *= -1;
                //cout << "Number1 = " << number1 << '\n';
 
                // Number 2
                bool inv2 = false;
                int number2 = 0;
                int idx_equal = -1;
                int qtd_dgt_2 = 0;
                for(int j = idx_op+1; j < s.size(); j++){
                    if(inv2 == false && s[idx_op+1] == '-') inv2 = true;
                    else if(s[j] == '='){
                        idx_equal = j;
                        break;
                    }
                    else if(s[j] == '?') number2 = number2*10 + i,qtd_dgt_2++;
                    else number2 = number2*10 + s[j] - '0',qtd_dgt_2++;
                }
                if(inv2) number2 *= -1;
                //cout << "Number2 = " << number2 << '\n';
                
                // Number 3
                int number3 = 0;
                bool inv3 = false;
                int qtd_dgt_3 = 0;
                for(int j = idx_equal+1; j < s.size(); j++){
                    if(inv3 == false && s[idx_equal+1] == '-') inv3 = true;
                    else if(s[j] == '?') number3 = number3*10 + i,qtd_dgt_3++;
                    else number3 = number3*10 + s[j] - '0',qtd_dgt_3++;
                }
                if(inv3) number3 *= -1;
                //cout << "Number3 = " << number3 << '\n';
 
                // Check
                // cout << "1º = " << number1 << " 2º = " << number2 << " 3º = " << number3 << '\n';
                // cout << "dgt1 = " << qtd_dgt_1 << " dgt2 = " << qtd_dgt_2 << " dgt3 = " << qtd_dgt_3 << '\n';
                if(i == 0){ // Leading zeros
                    if(inv1 == false && s[0] == '?' && qtd_dgt_1 > 1) continue;
                    if(inv1 && s[1] == '?' && qtd_dgt_1 > 1) continue;
                    if(inv2 == false && s[idx_op+1] == '?' && qtd_dgt_2 > 1) continue;
                    if(inv2 && s[idx_op+2] == '?' && qtd_dgt_2 > 1) continue;
                    if(inv3 == false && s[idx_equal+1] == '?' && qtd_dgt_3 > 1) continue;
                    if(inv3 == true && s[idx_equal+2] == '?' && qtd_dgt_3 > 1) continue;
                }
                if(s[idx_op] == '+'){
                    if(number1 + number2 == number3){
                        cout << i << '\n';
                        answ = true;
                        break;
                    }
                }
                else if(s[idx_op] == '-'){
                    if(number1 - number2 == number3){
                        cout << i << '\n';
                        answ = true;
                        break;
                    }
                }
                else if(s[idx_op] == '*'){
                    if(number1 * number2 == number3){
                        cout << i << '\n';
                        answ = true;
                        break;
                    }
                }
                // cout << "1º = " << number1 << " 2º = " << number2 << " 3º = " << number3 << '\n'; 
            }
        }
 
        if(answ == false) cout << -1 << '\n';
 
    }
 
    return 0;
}