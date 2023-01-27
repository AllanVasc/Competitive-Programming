// X - Wrench
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

string convert_to_decimal(int a, int b){
    string answ;
    for(int i = 0; i < 7; i++){
        a = (a%b)*10;
        answ += to_string(a/b);
        if(a/b) a -= b;
    }
    return answ;
}

bool check(string number_int, string number_decimal, string test_int, string test_decimal){
    if(number_int != test_int){
        return false;
    }

    int k = number_decimal.size();

    string normal;
    string roundup;

    for(int i = 0; i < k-1; i++){
        normal += test_decimal[i];
        roundup += test_decimal[i];
    }

    if(test_decimal[k] != '0'){
        normal += test_decimal[k-1];
        roundup += test_decimal[k-1] + 1;
    }
    else{
        normal += test_decimal[k-1];
        roundup += test_decimal[k-1];
    }
    // cout << "NUMBER DECIMAL: " << number_decimal << " N = " << normal << " R = " << roundup << '\n';
    if(number_decimal == normal || number_decimal == roundup) return true;
    else return false;
}

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
 
    while(t--){
        
        string s;
        cin >> s;

        string number_int;
        string number_decimal;

        bool dot = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '.'){
                dot = true;
            }
            else if(dot == false){
                number_int += s[i];
            }
            else{
                number_decimal += s[i];
            }
        }

        if(number_int.size() == 0){
            number_int.push_back('0');
        }
        if(number_decimal.size() == 0){
            number_decimal.push_back('0');
        }

        bool found = false;
        for(int b = 1; b <= 128 && !found; b*=2){
            for(int a = 1; a/b <= 10 && !found; a++){
                string test_int = to_string(a/b);
                string test_decimal = convert_to_decimal(a,b);
                // cout << "teste = " << test_int << "." << test_decimal <<  '\n';
                // break;
                if(check(number_int,number_decimal,test_int,test_decimal)){
                    if(a < b){
                        cout << a << "/" << b << "\"" << '\n';
                    }
                    else if(a%b == 0){
                        cout << a/b << "\"" << '\n';
                    }
                    else{
                        cout << a/b << " " << a%b << "/" << b << "\"" << '\n';
                    }
                    found = true;
                }
            }
        }
    }
    return 0;
}