// Time Complexity: O(N*M*N*M)
// Space Complexity: O(N*M)

class Solution {
    vector<pair<int,int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> reached(n, vector<int>(m,0));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        
        int total_buildings = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    bfs(grid, reached, dist, {i,j} );
                    total_buildings++;
                }
            }
        }
        
        int min_dist = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0 && reached[i][j] == total_buildings){
                    min_dist = min(min_dist, dist[i][j]);
                }
            }
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
private:
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &reached,
             vector<vector<int>> &dist, pair<int,int> start){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        queue<pair<pair<int,int>, int>> q;
        visited[start.first][start.second] = true;
        q.push({start,0});
        
        while(!q.empty()){
            pair<pair<int,int>,int> aux = q.front();
            pair<int,int> curr = aux.first;
            int curr_dist = aux.second;
            q.pop();
            
            for(auto i : dir){
                int r = curr.first + i.first;
                int c = curr.second + i.second;
                
                if(!is_valid(grid, visited, r, c)) continue;
                
                dist[r][c] += curr_dist + 1;
                reached[r][c]++;
                visited[r][c] = true;
                q.push({{r,c},curr_dist + 1});
            }
        }
    }
    
    bool is_valid(vector<vector<int>> &grid, vector<vector<bool>> &visited, 
                  int r, int c){
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(r >= n || r < 0 || c < 0 || c >= m) return false;
        if(grid[r][c] != 0) return false;
        if(visited[r][c]) return false;
        
        return true;
    }
};