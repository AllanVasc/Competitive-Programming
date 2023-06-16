#include <bits/stdc++.h>

using namespace std;
#define iii tuple<int,int,int>

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (3));
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }


    int best =-1;
    iii ans = {300, 300, 300};
    for(int i=0; i<=255; i++){
        for(int j=0; j<=255; j++){
            for(int k=0; k<=255; k++){
                int tome = 100000;
                for(int l=0; l<n; l++){
                    tome = min(tome, abs(i - v[l][0]) + abs(j - v[l][1]) + abs(k - v[l][2]));
                }
                iii aux = {i, j, k};
                if(tome > best || (tome == best && aux < ans)){
                    best = tome;
                    ans = aux;
                }
            }
        }
    }

    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << '\n';


}

//255 + 128
// 255 + 127
// 254 + 127