#include<bits/stdc++.h>
using namespace std;

#define int long long
int N, X, counter;
string aux, temp;
map<string, bool> res;
signed main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> X;
        temp = "";
        for (int j = 0; j < X; j++){
            cin >> aux;
            temp += aux[0];
        }
        if (not res.count(temp)){
            res[temp] = true;
            counter++;
        }else{
            if (res[temp]){
                counter--;
                res[temp] = false;
            }
        }
    }
    cout << counter  << '\n';
    return 0;
}