// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

bool isPal(int l, int r, string& s){
    while(l < r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

class ZFunction{
private:
    int n;
    vector<int> z;
    string s;

public:
    ZFunction(string& str){
        this->n = str.size();
        this->s = str;
        z.assign(n, 0);

        int l = 0, r = 0;
        for(int i = 1; i < n; i++){
            if(i <= r){
                z[i] = min(r-i+1,z[i-l]);
            }
            while(i+z[i] < n && str[z[i]] == str[i + z[i]]) z[i]++;
            if(i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
    }

    ii solve(){

        for(int i = 1; i < n; i++){
            if(z[i] == 0 || z[i] > i) continue;

            if(2*z[i] == n) return {i, n-1}; // PREF PREF

            if(z[i] == i){  // PREF PREF RESTO
                if(isPal(i+z[i], n-1, s)) return {i, n-1};
            }

            if(z[i] == n - i){ // PREF RESTO PREF
                if(isPal(z[i], i-1, s)) return {i, n-1};
            }
        }

        return {-1,-1};
    }
};


int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;

    int l = 0;
    int r = s.size() - 1;
    while(l < r && s[l] == s[r]){
        l++;
        r--;
    }

    if(l >= r){
        cout << "1 1" << '\n';
    }
    else{

        string aux;
        for(int i = l; i <= r; i++){
            aux += s[i];
        }
        cerr << "Check em: " << aux << '\n';

        ZFunction z_func(aux);

        ii answ = z_func.solve();
        cerr << "primeiro check: " << answ.first << " " << answ.second << '\n';

        if(answ.second == -1){
            reverse(aux.begin(), aux.end());
            z_func = ZFunction(aux);

            answ = z_func.solve();
            cerr << "segundo check: " << answ.first << " " << answ.second << '\n';
            
            if(answ.second != -1){
                answ.first = aux.size() - 1 - answ.first;
                answ.second = aux.size() - 1 - answ.second;
                swap(answ.first, answ.second);
            }
        }

        if(answ.second != -1){
            answ.first += l + 1;
            answ.second += l + 1;
        }

        cout << answ.first << " " << answ.second << '\n';
    }

    return 0;
}
