#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
 
    char who;
    int s;
    string word;
 
    cin >> who >> s >> word;
 
    for(int i = 0; i < word.size(); i++){
        if(who == 'E') cout << char((word[i] - 'a' + s)%26 + 'a'); 
        else cout << char((word[i] - 'a' - s + 26)%26 + 'a'); 
    }
    cout << '\n';
 
    return 0;
}