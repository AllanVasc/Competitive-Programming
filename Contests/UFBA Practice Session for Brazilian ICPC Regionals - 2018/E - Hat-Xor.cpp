#include<bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    string s;
    cin >> s;

    int total_1 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '1'){
            total_1 += 1;
        }
    }

    bool has_answ = false;
    int count_left = total_1;
    int count_right = 0;
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '1'){
            count_left--;
        }
        
        if(i == s.size()-1 && count_left%2 == 0){
            if(s[i] == '1'){
                break;
            }
        }
        else if(count_left%2 == count_right%2){
            if(s[i] != '0'){
                break;
            }
        }
        
        if(s[i] == '1'){
            count_right++;
        }

        if(i == 0){
            has_answ = true;
        }
    }


    if(has_answ){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
 
    return 0;
}