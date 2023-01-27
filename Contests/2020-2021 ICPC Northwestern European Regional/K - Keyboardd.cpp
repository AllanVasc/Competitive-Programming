//K. Keyboardd
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main(){ 
    
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    string input,output;
    map<char,ll> f1;
    map<char,ll> f2;
    
    getline(cin,input);
    getline(cin, output);
 
    for(int i = 0; i < input.size();i++){
        f1[input[i]]++;
    }
    for(int i = 0; i < output.size();i++){
        f2[output[i]]++;
    }
 
    vector<char> answer;
 
    for(auto it : f1){
 
        if(f2[it.first] != it.second){
            answer.push_back(it.first);
        }
 
    }
    
    for(int i = 0; i < answer.size(); i++){
 
        cout << answer[i];
    }
 
        cout << '\n';
 
    return 0;
}
 
 
/*
 
 
*/