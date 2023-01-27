// A - Linear Keyboard
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){

    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string alpha;
        cin >> alpha;

        vector<int> pos(26,0);

        for(int i = 0; i < alpha.size(); i++){
            pos[alpha[i] - 'a'] = i+1;
        }

        ll answer = 0;

        string input;
        cin >> input;

        for(int i = 0; i < input.size() - 1; i++){

            answer += abs(pos[input[i+1] - 'a'] - pos[input[i]- 'a']);
        }

        cout << answer << '\n';

    }

    return 0;
}