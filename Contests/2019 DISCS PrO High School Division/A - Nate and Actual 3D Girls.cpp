// 
#include <bits/stdc++.h>
using namespace std;
  
#define int long long
  
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int32_t main(){
  
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;

    vector<string> cards;
    cards.assign(n, "");

    for(int i = 0; i < n; i++) cin >> cards[i];

    map<int,int> freq;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < cards[i].size(); j++){
            freq[cards[i][j] -'a']++;
        }
    }

    vector<string> check;
    check.assign(m, "");
    for(int i = 0; i < m; i++) cin >> check[i];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < check[i].size(); j++){
            if(freq[(check[i][j] - 'a' + k)%26] == 0){
                cout << "It is gonna be daijoubu." << '\n';
                return 0;
            }
            else{
                freq[(check[i][j] - 'a' + k)%26]--;
            }
        }
    }
    cout << "Make her kokoro go doki-doki!" << '\n';

    return 0;
}