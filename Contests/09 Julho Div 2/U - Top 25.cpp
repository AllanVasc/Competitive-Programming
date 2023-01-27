//  U - Top 25
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
    
    int t;
    cin >> t;
 
    while(t--){
 
        int n;
        cin >> n;
 
        vector<int> list_1;
        vector<int> list_2;
 
        map<string,int> mapping;
 
        int count = 0;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(mapping[s] == 0){
                mapping[s] = count+1;
                count++;
            }
            list_1.push_back(mapping[s]);
        }
 
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(mapping[s] == 0){
                mapping[s] = count+1;
                count++;
            }
            list_2.push_back(mapping[s]);
        }
 
        int answ = 0;
        set<int> set_1;
        set<int> set_2;
 
        for(int i = 0; i < n; i++){
            answ++;
            set_1.insert(list_1[i]);
            set_2.insert(list_2[i]);
            if(set_1 == set_2){
                cout << answ << " ";
                answ = 0;
                set_1.clear();
                set_2.clear();
            }
        }
        cout << '\n';
    }
    return 0;
}