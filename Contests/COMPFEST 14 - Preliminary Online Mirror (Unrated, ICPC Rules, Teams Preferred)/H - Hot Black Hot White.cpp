#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <vector <int>> pos(3);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        pos[x%3].push_back(i);
    }

    //Olhando z = 0
    if(pos[0].size() <= n/2){
        vector <int> ans(n, 0);
        int qtd = 0;
        for(int i = 0; i < pos[0].size(); i++){
            ans[pos[0][i]] = 1;
            qtd++;
        }

        cout << "0\n";
        for(int i = 0; i < n; i++){
            if(ans[i]) cout << ans[i];
            else{
                if(qtd < n/2){
                    qtd++;
                    cout << 1;
                }
                else cout << ans[i];
            }
        }
        cout << "\n";

        return 0;
    }

    //Olhando z = 1
    if(pos[0].size() == 0 || pos[0].size() == n){
        cout << "1\n";
        for(int i = 0; i < n; i++){
            if(i < n/2) cout << "0";
            else cout << "1";
        }
        cout << "\n";

        return 0;
    }

    //Olhando z = 2
    if(pos[1].size() + pos[2].size() <= n/2){
        vector <int> ans(n,0);
        int qtd = 0;
        for(int i = 0; i < pos[1].size(); i++){
            ans[pos[1][i]] = 1;
            qtd++;
        }

        for(int i = 0; i < pos[2].size(); i++){
            ans[pos[2][i]] = 1;
            qtd++;
        }

        cout << "2\n";
        for(int i = 0; i < n; i++){
            if(ans[i]) cout << ans[i];
            else{
                if(qtd < n/2){
                    qtd++;
                    cout << 1;
                }
                else cout << ans[i];
            }
        }
        cout << "\n";

        return 0;
    }

    cout << "-1\n";

    return 0;
}