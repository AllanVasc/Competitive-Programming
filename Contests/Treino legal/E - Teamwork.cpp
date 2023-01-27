//  E - Teamwork
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    v.assign(n,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int answ = 0;

    while(!v.empty()){

        if(v.size() == 1){
            answ += v[0];
            v.erase(v.begin());
        }
        else if(v.size() == 2){
            answ += max(v[0],v[1]);
            v.erase(v.begin());
            v.erase(v.begin());
        }
        else if(v.size() == 3){
            answ += v[2];
            answ += v[0];
            answ += v[1];
            v.erase(v.begin());
            v.erase(v.begin());
            v.erase(v.begin());
        }
        else{

            int option_1 = 0; // Menor com maior

            option_1 += v[v.size()-1];
            option_1 += v[0];
            option_1 += v[v.size()-2];
            option_1 += v[0];

            int option_2 = 0; // (menor,menor) dps (maior,maior)
            option_2 += max(v[0],v[1]);
            option_2 += v[0];
            option_2 += max(v[v.size()-2], v[v.size()-1]);
            option_2 += v[1];
            
            if(option_1 < option_2){
                answ += option_1;
            }
            else{
                answ += option_2;
            }

            v.erase(v.end()-1);
            v.erase(v.end()-1);
        }

    }

    cout << answ << '\n';

    return 0;
}
