#include <bits/stdc++.h>
using namespace std;
  
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct Node{
    int dl, dr;
    char tl, tr;
    int idl, idr;
    Node(){}

    Node(int a, int b, char c, char d, int e, int f){
        dl = a;
        dr = b;
        tl = c;
        tr = d;
        idl = e;
        idr = f;
    }
};

vector<Node> arms;

int solve(int id_arm, int specialNode, int limitW, int tent){

    Node curr = arms[id_arm];
    int wleft = -1;
    int wright = -1;

    // cout << "id = " << id_arm << '\n';
    // cout << "tl = " << curr.tl << '\n';
    // cout << "tr = " << curr.tr << '\n';

    // Caso Base (Ambos são W)
    if(curr.tl == 'W' && curr.tr == 'W'){
        if(curr.idl != specialNode && curr.idr != specialNode){
            return curr.dl + curr.dr;
        }
        else{   // Um dos dois é o especial
            if(curr.idl == specialNode){ // Esquerda especial
                int wl = 0; 
                int g = gcd(curr.dr, curr.dl);
                int jump = curr.dl / g;
                int wr = 0;
                int cnt = 0;
                while(cnt < tent){
                    wr += jump;
                    wl = (wr * curr.dr) / curr.dl;
                    if(wl >= limitW) cnt++;
                }

                return (wl + wr);
            }
            else{   // Direita especial
                //cout << "id = " << id_arm << '\n';

                int wr = 0;
                int g = gcd(curr.dr, curr.dl);
                int jump = curr.dr / g;
                int wl = 0;
                int cnt = 0;
                while(cnt < tent){
                    wl += jump;
                    wr = (wl * curr.dl) / curr.dr;
                    if(wr >= limitW) cnt++;
                }
                // cout << "wl = " << wl << '\n';
                // cout << "wr = " << wr << '\n';
                return (wl + wr);
            }
        }
    }

    if(curr.tl == 'A'){
        wleft = solve(curr.idl, specialNode, limitW, tent);
    }
    if(curr.tr == 'A'){
        wright = solve(curr.idr, specialNode, limitW, tent);
    }

    // if(id_arm == 2){
    //     cout << "wleft = " << wleft << '\n';
    //     cout << "wright = " << wright << '\n';
    // }
    // Ambos são "A"
    if(wleft != -1 && wright != -1){
        int g = gcd(wleft * curr.dl, wright * curr.dr);
        int k1 = (wright * curr.dr) / g;
        int k2 = (wleft * curr.dl) / g;
        // if(id_arm == 2){
        //     cout << "k1 = " << k1 << '\n';
        //     cout << "k2 = " << k2 << '\n';
        // }
        return (wleft * k1 + wright * k2);
    }

    // Um dos dois são "W"
    if(wleft == -1){
        // Left = W
        if(curr.idl != specialNode){
            int g = gcd(curr.dl, wright * curr.dr);
            int k1 = (wright * curr.dr) / g;
            int k2 = (curr.dl) / g;

            // 1 pois menor valor de wl vai ser o proprio k1
            return (1 * k1 + wright * k2);
        }
        else{
            // o wleft tem restrição de minimo
            int wl = 0;
            int g = gcd(wright * curr.dr, curr.dl);
            int jump = curr.dl / g;
            int k2 = 0;
            int cnt = 0;
            while(cnt < tent){
                k2 += jump;
                wl = (wright * k2 * curr.dr) / curr.dl;
                if(wl >= limitW) cnt++;
            }

            return (wl + wright * k2);
        }
    }
    else{
        // Right = "W"
        if(curr.idr != specialNode){
            int g = gcd(wleft * curr.dl, curr.dr);
            int k1 = curr.dr / g;
            int k2 = (wleft * curr.dl) / g;

            return (wleft * k1 + 1 * k2);
        }
        else{
            // o wright tem restrição de minimo
            int wr = 0;
            int g = gcd(wleft * curr.dl, curr.dr);
            int jump = curr.dr / g;
            int k1 = 0;
            int cnt = 0;
            while(cnt < tent){
                k1 += jump;
                wr = (wleft * k1 * curr.dl) / curr.dr;
                if(wr >= limitW) cnt++;
            }

            return (wleft * k1 + wr);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    int cnt = 1;
    while(cin >> n){
        if(n == 0) break;

        arms.resize(n + 1);
        vector<int> freq(n + 1, 0);
        for(int i = 0; i < n; i++){
            int dl, dr;
            char tl, tr;
            int idl, idr;
            cin >> dl >> dr >> tl >> tr >> idl >> idr;
            Node aux(dl,dr,tl,tr,idl,idr);
            if(tl == 'A'){
                freq[idl]++;
            }
            if(tr == 'A'){
                freq[idr]++;
            }
            arms[i + 1] = aux;
        }

        int root = -1;
        for(int i = 1; i <= n; i++){
            if(freq[i] == 0) root = i;
        }

        int specialW, limit;
        cin >> specialW >> limit;

        int answ = INF;
        for(int i = 1; i <= 50; i++){
            answ = min(answ, solve(root, specialW, limit, i)); 
        }
        cout << "Case " << cnt++ << ": " << answ << "\n";
    }

    return 0;
}