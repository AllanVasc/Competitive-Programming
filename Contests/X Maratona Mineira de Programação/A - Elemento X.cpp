#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(4);
    for(int i = 0; i < 4; i++) cin >> v[i];

    for(int i = 0; i < 4; i++){
        if(v[i] >= 4){
            cout << i + 1 << '\n';
            return 0;
        }
    }

    if(v[1] == 1 && v[2] == 2 && v[3] == 3){
        cout << 1 << '\n';
    }
    else if(v[0] == 1 && v[2] == 1 && v[3] == 2){
        cout << 2 << '\n';
    }
    else if(v[0] == 2 && v[1] == 1 && v[3] == 1){
        cout << 3 << '\n';
    }
    else{
        cout << 4 << '\n';
    }
   
}