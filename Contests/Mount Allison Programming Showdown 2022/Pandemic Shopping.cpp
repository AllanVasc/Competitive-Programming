// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> direction;
vector<int> fat2;

int solve(int a, int b){

    int n = direction.size();

    if(a == b){

        if(n%2 == 0){
            return 0;
        }

        if(a == 1){
            bool check = true;
            for(int i = 0; i < n; i++){
                if(direction[i] == -1) continue;
                if(i%2 == 0){
                    if(direction[i] == 0) check = false;
                }
                else{
                    if(direction[i] == 1) check = false;
                }
            }

            if(check) return 1;
            else return 0;
        }
        else{
            bool check = true;
            for(int i = 0; i < n; i++){
                if(direction[i] == -1) continue;
                if(i%2 == 0){
                    if(direction[i] == 1) check = false;
                }
                else{
                    if(direction[i] == 0) check = false;
                }
            }

            if(check) return 1;
            else return 0;
        }

    }
    else{

        if(a == 1){
            if(direction[0] == 1 || direction.back() == 0) return 0;
        }
        else{
             if(direction[0] == 0 || direction.back() == 1) return 0;
        }
        
        int k = 0;
        for(int i = 1; i < n-1; i++){
            if(direction[i] == -1) k++;
        }

        return fat2[k];
    }
}


int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    fat2.assign(33, 1);
    for(int i = 1; i < 33; i++){
        fat2[i] = 2*fat2[i-1];
    }

    direction.assign(n, -1);

    // 0 -> A
    // 1 -> B
    // 2 -> 1
    // ...

    int dir_a = -1;
    int dir_b = -1;

    for(int i = 0; i < k; i++){
        string id, dir;
        cin >> id >> dir;

        if(id[0] == 'A' || id[0] == 'B'){ // A ou B
            
            if(id[0] == 'A'){
                if(dir[0] == 'S'){  // Subindo -> 1
                    dir_a = 1;
                }
                else{   // Descendo -> 0
                    dir_a = 0;
                }
            }
            else{
                if(dir[0] == 'S'){  // Subindo -> 1
                    dir_b = 1;
                }
                else{   // Descendo -> 0
                    dir_b = 0;
                }
            }
            
        }
        else{
            if(dir[0] == 'E'){  // Esquerda -> 0
                direction[stoi(id) - 1] = 0;
            }
            else{
                direction[stoi(id) - 1] = 1;
            }
        }
    }

    int answ = 0;
    if(dir_a == -1 && dir_b == -1){
        answ += solve(0,0);
        answ += solve(0,1);
        answ += solve(1,0);
        answ += solve(1,1);
    }
    else if(dir_a == -1){
        answ += solve(0, dir_b);
        answ += solve(1, dir_b);
    }
    else if(dir_b == -1){
        answ += solve(dir_a, 0);
        answ += solve(dir_a, 1);
    }
    else{
        answ += solve(dir_a, dir_b);
    }

    cout << answ << '\n';

    return 0;
}