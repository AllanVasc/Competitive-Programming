#include <bits/stdc++.h>

using namespace std;

#define int long long
int cnt = 0;
string ask(int l, int r){
    cnt++;
    cout << l << " " << r << endl;
    string s; cin >> s;
    return s;
}

int fix(int st, int en){
    // cout << "fixing" << endl;
    // cout << "[" << st << "," << en << "]" << endl;
    // [st, en] ta ordenado
    for(int i = en; i > st; i--){
        string resp = ask(i - 1, i);
        if(resp == "WIN") return -1;
        if(resp == "SWAPPED"){ // o cara errado ta em (i - 1) mas o i tbm ta errado
            for(int j = 1; j < i - 1; j++){
                string resp = ask(j, i - 1);
                if(resp == "WIN") return -1;
            }
            // Garanti que o maior possivel ta em (i - 1);
            ask(i - 1, i);
            return 1;
        }
    }
    return 0;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    for(int r = n; r > 0; r--){ // To tentando ordenar o "r"
        for(int l = 1; l < r; l++){
            string resp = ask(l, r);
            if(resp == "WIN"){
                return 0;
            }
            if(cnt == 2 * n){
                cnt = 0;
                // Precisa corrigir
                int feedback = 0;
                feedback = fix(r + 1, n);
                // cout << "end fixing" << endl;
                if(feedback < 0) return 0;
                l = 0;
                r++;
            }
        }
    }
    return 0;
}