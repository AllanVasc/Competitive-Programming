#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, w, h, s;
    cin >> n >> w >> h >> s;

    char letter;
    int amount = 0;

    for(int i = 0; i < n; i++){
        char l;
        cin >> l;

        for(int j = 0; j < h; j++){
            int qnt_s = 0;
            char state = '.';
            for(int k = 0; k < w; k++){
                char x;
                cin >> x;

                if(x != state) qnt_s++;
                state = x;
            }

            if(state != '.') qnt_s++;

            if(qnt_s > amount){
                letter = l;
                amount = qnt_s;
            }
        }
    }

    for(int i = 0; i < s; i += amount)
        cout << letter;
    
    cout << "\n";

    return 0;
}