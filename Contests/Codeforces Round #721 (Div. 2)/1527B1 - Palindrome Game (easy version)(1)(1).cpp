//1527B1 - Palindrome Game (easy version)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1000][1000][2][2];
bool check[1000][1000][2][2];

int solve(int zeroPalindromo, int zeroNormal, int vez, int reverse){

    if(zeroPalindromo == zeroNormal && zeroPalindromo == 0){
        return 0;
    }

    if(check[zeroPalindromo][zeroNormal][vez][reverse]){
        return dp[zeroPalindromo][zeroNormal][vez][reverse];
    }

    int answer;

    if(vez == 1){ // é bob

        answer = 50000;

        if(reverse == 0 && zeroNormal != 0){ //Jogada passada não foi reverse e não é palindromo
            answer = min (answer, solve(zeroPalindromo,zeroNormal,1-vez,1));
        }
        if(zeroPalindromo & 1){ //Pintar o do meio
            answer = min (answer,1 + solve(zeroPalindromo-1,zeroNormal,1-vez,0) );
        }
        if(zeroNormal != 0){ //Posso pintar um zero normal
            answer = min (answer,1 + solve(zeroPalindromo,zeroNormal-1,1-vez,0));
        }
        if(zeroPalindromo >= 2){ //Posso pintar um palindromo
            answer = min (answer,1 + solve(zeroPalindromo-2,zeroNormal+1,1-vez,0));
        }

    }
    else{ //é alice

        answer = -50000;

        if(reverse == 0 && zeroNormal != 0){ //Jogada passada não foi reverse e não é palindromo
            answer = max (answer,solve(zeroPalindromo,zeroNormal,1-vez,1));
        }
        if(zeroPalindromo & 1){ //Pintar o do meio
            answer = max (answer,solve(zeroPalindromo-1,zeroNormal,1-vez,0)-1);
        }
        if(zeroNormal != 0){ //Posso pintar um zero normal
            answer = max (answer,solve(zeroPalindromo,zeroNormal-1,1-vez,0)-1);
        }
        if(zeroPalindromo >= 2){ //Posso pintar um palindromo
            answer = max (answer,solve(zeroPalindromo-2,zeroNormal+1,1-vez,0)-1);
        }
    }

    check[zeroPalindromo][zeroNormal][vez][reverse] = true;
    return dp[zeroPalindromo][zeroNormal][vez][reverse] = answer;
}
 
int main(){

    int qtdTestes;
    cin >> qtdTestes;

    while(qtdTestes--){

        int n;
        string input;
        cin >> n >> input;

        int zeroPalindromo = 0;
        int zeroNormal = 0;

        int l = 0;
        int r = input.size() - 1;

        while(l <= r){

            if(input[l] == '0' && input[r] == '0' && l != r){
                zeroPalindromo+=2;
            }
            else if(input[l] == '0' && input[r] == '0' && l == r){
                zeroPalindromo++;
            }
            else if(input[l] == '0' || input[r] == '0'){
                zeroNormal++;
            }
            l++;
            r--;
        }

        //cout << "zp: " << zeroPalindromo << endl;
        //cout << "zn: " << zeroNormal << endl;

        if(solve(zeroPalindromo,zeroNormal,0,0) > 0){

            cout << "ALICE" << '\n';
        }
        else if(solve(zeroPalindromo,zeroNormal,0,0) < 0){
            cout << "BOB" << '\n';
        }
        else{
            cout << "DRAW" << '\n';
        }

    }
}

/*
 
 
*/