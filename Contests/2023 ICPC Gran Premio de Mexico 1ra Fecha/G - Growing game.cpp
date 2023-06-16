#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, turn = 1, aux = 1;
    cin >> n;
    bool isJane = true, repeat = false;
    vector<bool> dp(5001);
    for (int i = 1; i <= 5000; i++){
        if (aux == 0){
            if (not repeat){
                turn++;
            }
            aux = turn;
            isJane = !isJane;
            repeat = !repeat;
        }

        if (aux != 0){
            aux--;
            dp[i] = isJane;
        }

    }
    if (dp[n] == true){
        cout << "Jane";
    }else{
        cout << "John";
    }
    
    return 0;
}