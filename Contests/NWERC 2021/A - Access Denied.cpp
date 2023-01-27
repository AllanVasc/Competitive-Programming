#include <bits/stdc++.h>
using namespace std;

vector<char> dict = { 'a', 'b', 'c', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z',
                      'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'X', 'W', 'Y', 'Z',
                      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int picknumber(string& s){
    int value = 0;
    for(int i = 0; i < s.size() && value == 0; i++){
        while(isdigit(s[i])){
            // cout << i << " " << s[i] << '\n';
            value = 10*value + s[i] - '0';
            i++;
        }
    }

    return value;
}

int main(){

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    string chute = "a";
    string resposta;
    cout << chute << endl;
    getline(cin,resposta);

    if(resposta == "ACCESS GRANTED"){
        return 0;
    }

    int curr_time = picknumber(resposta);

    while(curr_time == 5){
        chute += "a";
        cout << chute << endl;
        getline(cin, resposta);

        if(resposta == "ACCESS GRANTED"){
            return 0;
        }

        curr_time = picknumber(resposta);
    }

    // tenho o tamanho correto

    int prev = curr_time;
    for(int i = 0; i < chute.size(); i++){
        for(int j = 1; j < dict.size(); j++){
            chute[i] = dict[j];
            cout << chute << endl;
            getline(cin, resposta);

            if(resposta == "ACCESS GRANTED"){
                return 0;
            }

            curr_time = picknumber(resposta);
            if(curr_time > prev){
                prev = curr_time;
                break;
            }
            else if(curr_time < prev){  // a letra era "a"
                chute[i] = dict[j-1];
                break;
            }
        }
    }

    cout << chute << endl;

    return 0;
}