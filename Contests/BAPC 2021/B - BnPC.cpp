// 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int inf = 1e18;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
using ll = long long;
const int INF = 1e18;

int32_t main(){
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    map<string, int> start;
    map<string, vector<int>> events;
    map<string, int> maxevents;
    map<string, int> equal;
    map<string, int> less;

    for(int i = 0; i < n; i++){
        string s;
        int x;
        cin >> s >> x;
        start[s] = x;
        maxevents[s] = max(maxevents[s],x);
    }

    int l;
    cin >> l;

    for(int i = 0; i < l; i++){
        string s;
        int value;
        cin >> s >> value;
        events[s].push_back(value);
        maxevents[s] = max(maxevents[s],value);
    }

    for(auto i: events){    // Count less and equal
        string s = i.first;
        for(auto j : i.second){
            if(maxevents[s] == j) equal[s]++;
            else less[s]++;
        }
    }

    int answ = 0;

    for(auto i : start){
        k -= maxevents[i.first] - i.second;
    }

    if(k < 0){
        cout << answ << '\n';
    }
    else{
        priority_queue<pair<int, string>> pq;
        map<string,bool> visited;

        for(auto i : events){
            string name = i.first;
            answ += less[i.first]*maxevents[i.first];
            pq.push({maxevents[name]*equal[name] + (less[name] + equal[name]), name});
        }

        while(k){

            pair<int,string> maior = pq.top();
            pq.pop();

            if(visited[maior.second] == 0){
                visited[maior.second] = 1;
                answ += maior.first;

                pq.push({less[maior.second] + equal[maior.second], maior.second});
                k--;
            }
            else{
                answ += k*maior.first;
                k -= k;
            } 
        }
        cout << answ << '\n';
    }
    return 0;
}
