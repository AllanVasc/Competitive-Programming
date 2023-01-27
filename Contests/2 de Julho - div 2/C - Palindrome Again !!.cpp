// C - Palindrome Again !!
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

const int MAXN = 200000 + 100;

int calc(char a, char b){
    int op1 = a - b;
    if(op1 < 0) op1 += 26;
    int op2 = b - a;
    if(op2 < 0) op2 += 26;
    return min(op1,op2);
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,p;
        cin >> n >> p;

        string s;
        cin >> s;

        int answ = 0;

        if((n%2 == 0 && p <= n/2) || (n%2 == 1 && p <= (n/2 + 1))){ // To na metade esquerda
            int idx_most_left = p-1;

            for(int i = p-1; i >= 0; i--){ // Vai pra esquerda
                if(s[i] != s[n-i-1]){
                   answ += calc(s[i],s[n-i-1]);
                   //cout << "Dif: " << i << " " << n-i-1 << " Cost = " << calc(s[i],s[n-i-1]) << '\n';
                   idx_most_left = i;
                }
            }

            int idx_most_right = p-1;

            for(int i = p; i < n/2; i++){
                if(s[i] != s[n-i-1]){
                   answ += calc(s[i],s[n-i-1]);
                   //cout << "Dif: " << i << " " << n-i-1 << " Cost = " << calc(s[i],s[n-i-1]) << '\n';
                   idx_most_right = i;
                }
            }

            if(abs(p-1 - idx_most_left) <= abs(p-1-idx_most_right))
                answ += 2*abs(p-1 - idx_most_left) + abs(p-1-idx_most_right);
            else
                answ += 2*abs(p-1-idx_most_right) + abs(p-1 - idx_most_left);

            cout << answ << '\n';
        }
        else{ // To na metade direita
            int idx_most_left = p-1;

            for(int i = p-1; i >= n/2; i--){ // Vai pra esquerda
                if(s[i] != s[n-i-1]){
                   answ += calc(s[i],s[n-i-1]);
                   //cout << "Dif: " << i << " " << n-i-1 << " Cost = " << calc(s[i],s[n-i-1]) << '\n';
                   idx_most_left = i;
                }
            }
            int idx_most_right = p-1;

            for(int i = p; i < n; i++){
                if(s[i] != s[n-i-1]){
                   answ += calc(s[i],s[n-i-1]);
                   //cout << "Dif: " << i << " " << n-i-1 << " Cost = " << calc(s[i],s[n-i-1]) << '\n';
                   idx_most_right = i;
                }
            }
            if(abs(p-1 - idx_most_left) <= abs(p-1-idx_most_right))
                answ += 2*abs(p-1 - idx_most_left) + abs(p-1-idx_most_right);
            else
                answ += 2*abs(p-1-idx_most_right) + abs(p-1 - idx_most_left);

            cout << answ << '\n';
        }
    }
    return 0;
}
