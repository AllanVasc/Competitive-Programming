// 
#include <bits/stdc++.h>
using namespace std;
 
const int inf = 0x3f3f3f3f;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<bool> values;
    values.assign(n,0);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        if(s[0] == 'T') values[i] = true;
        else values[i] = false;
    }

    string s;
    stack<bool> st;
    while(cin >> s){

        if(isalpha(s[0])) st.push(values[s[0]-'A']);
        else if(s[0] == '*'){
            bool x = st.top();
            st.pop();
            bool y = st.top();
            st.pop();
            st.push(x&&y);
        }
        else if(s[0] == '+'){
            bool x = st.top();
            st.pop();
            bool y = st.top();
            st.pop();
            st.push(x||y);
        }
        else{
            bool x = st.top();
            st.pop();
            st.push(!x);
        }

    }

    if(st.top() == 0) cout << "F" << '\n';
    else cout << 'T' << '\n';

}