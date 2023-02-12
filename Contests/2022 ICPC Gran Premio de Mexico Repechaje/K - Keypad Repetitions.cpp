#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> mapping = { '2', '2', '2',
                        '3', '3', '3',
                        '4', '4', '4',
                        '5', '5', '5',
                        '6', '6', '6',
                        '7', '7', '7', '7',
                        '8', '8', '8',
                        '9', '9', '9', '9'};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;

    map<string, int> freq;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        string translated;
        for(int j = 0; j < s.size(); j++){
            translated.push_back(mapping[s[j] - 'a']);
        }
        freq[translated]++;

    }

    for(int i = 0; i < q; i++){
        string check;
        cin >> check;
        cout << freq[check] << '\n';
    }
    
    return 0;
}