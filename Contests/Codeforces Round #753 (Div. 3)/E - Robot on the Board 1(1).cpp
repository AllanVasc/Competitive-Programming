// E - Robot on the Board 1
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int altura, largura;
        string s;

        cin >> altura >> largura >> s;

        int max_x = 0, max_y = 0, min_x = 0, min_y = 0;
        int posX = 0, posY = 0;

        for(int i = 0; i < s.size(); i++){

            if(s[i] == 'R') max_x = max(max_x, ++posX);
            else if(s[i] == 'L') min_x = min(min_x, --posX);
            else if(s[i] == 'D') max_y = max(max_y, ++posY);
            else if(s[i] == 'U') min_y = min(min_y, --posY);

            if(max_x - min_x >= largura){
                if(posX == min_x) min_x++;
                break;
            }

            if(max_y - min_y >= altura){
                if(posY == min_y) min_y++;
                break;
            }
        } 

        cout << 1 - min_y << ' ' << 1 - min_x << '\n'; 

    }
    return 0;
}