// C - Detective Task
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string s;
        cin >> s;

        int idx = 0;
        int answer = 0;

        for(int i = s.size()-1; i >= 0; i--){   // Last "1"
            
            if(s[i] == '1'){
                idx = i;
                break;
            }
        }

        for(int i = idx; i < s.size(); i++){
            answer++;
            if(s[i] == '0') break;
        }

        cout << answer << '\n';
        
        
    }

    return 0;
}
