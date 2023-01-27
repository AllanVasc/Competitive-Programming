// I. Induced Metric Space
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qtdTestes; cin >> qtdTestes;

    while(qtdTestes--){

        int n; cin >> n;

        vector<vector<ll>> d (n,vector<ll>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> d[i][j];
            }
        }

        // Entrada Lida!

        bool ok = true;
        for(int i=0;i<n;++i){
            if(d[i][i] == -1) d[i][i] = 0;
            if(d[i][i] != 0) ok = false;
            for(int j=0;j<n;++j){
                if(d[i][j] == d[j][i] && d[i][j] == -1){
                    d[i][j] = d[j][i] = INF;
                }
                if(d[i][j] == -1){
                    d[i][j] = d[j][i];
                }
                if(d[j][i] == -1){
                    d[j][i] = d[i][j];
                }
 
                if(d[i][j] != d[j][i]) ok = false;
            }
        }

        vector<vector<ll>> dist = d;
        for(int k=0;k<n;++k){ //Floyd-warshall
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){

                if(d[i][j] != INF){
                    ok &= d[i][j] == dist[i][j];
                }
                ok &= dist[i][j] == dist[j][i];
                
            }
        }

        if(ok){
            cout<<"YES\n";
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    cout<<dist[i][j]<<' ';
                }
                cout<<'\n';
            }
        }else{
            cout<<"NO\n";
        }

    }

    
    return 0;
}

/*


*/