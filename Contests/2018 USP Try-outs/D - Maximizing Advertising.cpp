#include <bits/stdc++.h>
using namespace std;

#define int long long

const int ms = 2 * 1e3;

template<class T>
struct CoordinateCompression{
    vector<T> v;
    void push(const T & a) { v.push_back(a); }
    int build(){
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        return (int) v.size();
    }
    int operator[] (const T & a){
        auto it = lower_bound(v.begin(), v.end(), a);
        return it - v.begin();
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
        int x, y;
        string s;
        cin >> x >> y >> s;
        v.emplace_back(x, y, s[0] == 'b');
    }
    CoordinateCompression<int> cd;
    for(int i = 0; i < n; i++){
        auto [x, y, c] = v[i];
        cd.push(x);
        cd.push(y);
    }

    // x primeiro 
    int szCd = cd.build();
    vector<int> psB(szCd + 5, 0);
    vector<int> psW(szCd + 5, 0);
    for(int i = 0; i < n; i++){
        auto [x, y, c] = v[i];
        if(c == 0){
            //w
            psW[cd[x]]++;
        }
        else{
            psB[cd[x]]++;
        }
    }
    for(int i = 1; i < psB.size(); i++){
        psB[i] += psB[i - 1];
        psW[i] += psW[i - 1];
    }
    // cout << "debug prefixSum black: ";
    // for(auto x : psB){
    //     cout << x << " ";
    // }
    // cout << '\n';
    // cout << "debug prefixSum white: ";
    // for(auto x : psW){
    //     cout << x << " ";
    // }
    // cout << '\n';

    int answX = max(psB.back(), psW.back());
    for(int i = 0; i < psB.size(); i++){
        int curr = psB[i] + psW.back() - psW[i];
        answX = max(answX, curr);
        curr = psW[i] + psB.back() - psB[i];
        answX = max(answX, curr);
    }

    // cout << "check no x answ = " << answX << '\n';
    psB.assign(szCd + 5, 0);
    psW.assign(szCd + 5, 0);
    for(int i = 0; i < n; i++){
        auto [x, y, c] = v[i];
        if(c == 0){
            //w
            psW[cd[y]]++;
        }
        else{
            psB[cd[y]]++;
        }
    }
    for(int i = 1; i < psB.size(); i++){
        psB[i] += psB[i - 1];
        psW[i] += psW[i - 1];
    }
    int answY = max(psB.back(), psW.back());
    for(int i = 0; i < psB.size(); i++){
        int curr = psB[i] + psW.back() - psW[i];
        answY = max(answY, curr);
        curr = psW[i] + psB.back() - psB[i];
        answY = max(answY, curr);
    }
    // cout << "check no y = " << answY << '\n';

    cout << max(answX, answY) << '\n';
    return 0;
}