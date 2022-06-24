#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;

// Graph implementation using matrix
vector<vector<int>> g;

// Implementation of the Stoer-Wagner algorithm to find the global min cut of a graph
// We'll use this algorithm for problems where we don't know exactly where the source or sink is
int stoer_wagner(int n){
    int answ = LONG_LONG_MAX;
    for(int i = 1; i < n; i++){   // Need to repeat only n-1 times
        vector<int> weight(n, 0);
        vector<bool> visited(n, false);

        int prev = -1, v = 0, cnt = 1, current_cut = 0;
        while(cnt <= n-i){ // Creating the subset until only 1 node is missing
            visited[v] = true;
            int nxt = -1;
            current_cut = 0;

            for(int j = 0; j < n; j++){ // Looking for edge with the greatest weight connected to current subset
                weight[j] += g[v][j];
                if(!visited[j] && weight[j] > current_cut){
                    nxt = j;
                    current_cut = weight[j];
                }
            }

            cnt++;
            prev = v;
            v = nxt;
        } // At the end of the loop "v" is the disconnected node and "prev" was the last node that reached it

        answ = min(answ, current_cut);
        for(int j = 0; j < n; j++){ // Joining the last 2 nodes, putting the edges of "v" in "prev"
            if(j != prev){
                g[j][prev] += g[j][v];
                g[prev][j] += g[v][j];
            }
            g[j][v] = 0; // Emptying the weights to "v" because "v" will no longer exist
        }
    }
    return answ;
}


/*

Time Complexity

stoer_wagner    -> O(V^3) can be optimized to O(|V|*|E| + |V|²*log|V|)

Links:

https://www.youtube.com/watch?v=AtkEpr7dsW4
https://blog.thomasjungblut.com/graph/mincut/mincut/

*/