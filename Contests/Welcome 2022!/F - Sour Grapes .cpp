// F - Sour Grapes 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> suffixSum(n+1,0);
    reverse(s.begin(), s.end());

    multiset<ll,greater<ll>> mSet;
    mSet.insert(suffixSum[0]);

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'C')
            suffixSum[i+1] += suffixSum[i] + 1;
        else if(s[i] == 'R')
            suffixSum[i+1] += suffixSum[i] - 1;
        else if(s[i] == 'S')
            suffixSum[i+1] += suffixSum[i] - 2;

        mSet.insert(suffixSum[i+1]);
    }

    reverse(s.begin(), s.end());

    ll answ = 0 + *mSet.begin();
    ll sumL = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R')
            sumL += 1;
        else if(s[i] == 'C')
            sumL += -1;
        else if(s[i] == 'S')
            sumL += -2;

        auto pos = mSet.find(suffixSum[n-i]);
        mSet.erase(pos);

        answ = max(answ, sumL + *mSet.begin());
    }

    cout << answ << '\n';

    return 0;
}