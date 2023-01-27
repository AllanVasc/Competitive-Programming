#include<bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<string> g;

vector<pair<int,int>> dir = { {1,0}, {0,1}, {-1,0}, {0,-1} };

void preprocess(vector<pair<int,int>>& points, int n, int m, int step){

    queue<pair<pair<int,int>,int>> q;
    for(int i = 0; i < points.size(); i++){
        q.push({points[i],0});
        g[points[i].first][points[i].second] = 'X';
    }

    while(!q.empty()){

        pair<pair<int,int>, int> aux = q.front();
        q.pop();
        pair<int,int> curr_point = aux.first;
        int distance = aux.second;

        if(distance >= step) continue;

        for(auto i : dir){
            int rc = curr_point.first + i.first;
            int cc = curr_point.second + i.second;

            if( (rc < 0 || cc < 0 || rc >= n || cc >= m) || g[rc][cc] == 'X' ) continue;
            g[rc][cc] = 'X';
            q.push({{rc,cc}, distance + 1});
        }
    }

}

int bfs(int i, int j, int n, int m){

    queue<pair<pair<int,int>,int>> q;
    q.push({{i,j}, 0});
    g[i][j] = 'X';

    while(!q.empty()){

        pair<pair<int,int>, int> aux = q.front();
        q.pop();
        pair<int,int> curr_point = aux.first;
        int distance = aux.second;

        for(auto i : dir){
            int rc = curr_point.first + i.first;
            int cc = curr_point.second + i.second;

            if(rc < 0 || cc < 0 || rc >= n || cc >= m) continue;
            if(g[rc][cc] == 'X') continue;
            if(g[rc][cc] == 'F') return distance + 1;

            g[rc][cc] = 'X';
            q.push({{rc,cc}, distance + 1});
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int n,m,d;
    cin >> n >> m >> d;

    for(int i = 0; i < n; i++){
        string aux;
        cin >> aux;
        g.push_back(aux);
    }
    vector<pair<int,int>> points;

    for(int i = 0; i < n; i++){ // preprocess
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'M'){
                points.push_back({i,j});
                // cout << "mostro em " << i << " " << j << '\n';
            }
        }
    }

    preprocess(points,n,m,d);

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';


    int answ = -1;
    for(int i = 0; i < n; i++){ // preprocess
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'S'){
                answ = bfs(i,j,n,m);
            }
        }
    }

    cout << answ << '\n';
    
}