// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int INF = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> freq(3,0);
    for(int i = 0; i < 3*n; i++){
        freq[s[i]-'A']++;
    }

    vector<char> major;
    for(int i = 0; i < 3; i++){
        if(freq[i] >= n) major.push_back('A' + i);
    }

    if(major.size() == 3){ // 0 troca
        cout << 0 << '\n';
        return 0;
    }
    else if(major.size() == 2){ // 1 unica troca

        vector<char> minor;
        for(int i = 0; i < 3; i++){
            if(freq[i] < n) minor.push_back('A' + i);
        }

        int toReplace1 = freq[major[0]-'A'] - n;
        int toReplace2 = freq[major[1]-'A'] - n;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0, l = 0; i < 3*n; i++){
            if(s[i] == major[0]) cnt1++;
            else if(s[i] == major[1]) cnt2++;

            while(l < i && (cnt1 > toReplace1 || cnt2 > toReplace2)){
                if(s[l] == major[0]) cnt1--;
                else if(s[l] == major[1]) cnt2--;
                l++;
            }
            while(l < i && s[l] == minor[0]){
                l++;
            }
            if( make_pair(cnt1,cnt2) == make_pair(toReplace1,toReplace2)){
                cout << 1 << '\n';
                cout << l+1 << " " << i+1 << " " << minor[0] << '\n';
                return 0;
            }
        }
    }
    // Need 2 changes
        
    vector<char> check;
    check.push_back('A');
    check.push_back('B');
    check.push_back('C');

    for(int i = 0; i < 3; i++){
        vector<char> diff;
        for(int j = 0; j < 3; j++){
            if(j != i) diff.push_back(check[j]);
        }
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;

        for(int j = 0; j < 3*n; j++){

            if(s[j] == check[i]){
                count1++;
            }
            else if(s[j] == diff[0]){
                count2++;
            }
            else if(s[j] == diff[1]){
                count3++;
            }

            if(count1 == n && count2 < n && count3 < n){
                cout << 2 << '\n';
                int l = j+1;
                // while(s[l] == diff[0]) l++;
                cout << l+1 << " " << j+1+n-count2 << " " << diff[0] << '\n';

                l = j+1+n-count2;
                //while(s[l] == diff[1]) l++;
                cout << l+1 << " " << 3*n << " " << diff[1] << '\n';
                return 0;
            }
        }
    }
    return 0;
}