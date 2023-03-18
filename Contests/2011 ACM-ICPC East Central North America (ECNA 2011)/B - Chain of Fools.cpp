#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int s, c, p, l;
    int cnt = 1;
    while(cin >> s >> c >> p >> l){
        if(s == c && c == p && p == l && l == 0) break;
        cout << "Case " << cnt << ": ";
        cnt++;

        int offset;
        if(p != 0) offset = s - p;
        else offset = 0;
        
        int cur_pos = c - offset;
        set<int> pos;
        pos.insert(c - offset);
        bool has_answ = true;
        while(pos.count(l) == 0){
            cur_pos = ((cur_pos - s) + c) % c;
            if(pos.count(cur_pos) > 0){
                has_answ = false;
                break;
            }
            pos.insert(cur_pos);
        }

        if(has_answ){
            cout << pos.size() - 1 << " " << offset << "/" << s << '\n';
        }
        else{
            cout << "Never" << '\n';
        }
    }
    return 0;
}