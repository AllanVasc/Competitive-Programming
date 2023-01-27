#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    
    vector<pair<int,int>> edges;
    stack<int> st;

    for(int i = 0; i < 2*n; i++){
        string command;
        int u;
        cin >> command >> u;

        if(command[0] == 'i'){
            if(!st.empty()){
                edges.push_back({st.top(), u});
            }
            st.push(u);
        }
        else{
            st.pop();
        }
    }

    for(int i = 0; i < edges.size(); i++){
        cout << edges[i].first << " " << edges[i].second << '\n';
    }
}