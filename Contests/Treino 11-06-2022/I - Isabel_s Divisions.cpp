// I - Isabel's Divisions
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
 
int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    string s;
    cin >> s;
 
    vector<int> numbers;
 
    for(int i = 0; i < s.size(); i++){
        if(s[i] - '0') numbers.push_back(s[i] - '0');
    }
 
    int n = stoi(s);
 
    int answ = 0;
 
    for(int i = 0; i < numbers.size(); i++){
        if(n % numbers[i] == 0) answ++;
    }
 
    cout << answ << '\n';
    return 0;
}
