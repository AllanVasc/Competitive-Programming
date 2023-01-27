// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        return bfs(grid, {0,0}, grid.size());
    }
    
private:
    int bfs(vector<vector<int>>& grid, pair<int,int> start, int n){
        
        queue<pair<pair<int,int>, int>> q;
        if(!grid[start.first][start.second])
            q.push({start, 1});
        
        grid[0][0] = 1;
        
        vector<pair<int,int>> dir = { {0,1}, {1,0}, {0, -1}, {-1, 0}, {1,1}, {1,-1}, {-1, 1}, {-1,-1} };
        
        while(!q.empty()){
            pair<int,int> point = q.front().first;
            int dist = q.front().second;
            q.pop(); 
            
            if(point.first == n-1 && point.second == n-1){    // Found
                return dist;
            }
            
            for(auto offset : dir){
                int r = point.first + offset.first;
                int c = point.second + offset.second;
                
                if(r >= 0 && c >= 0 && r < n && c < n && !grid[r][c]){
                    q.push({{r,c},dist+1});
                    grid[r][c] = 1;
                }
            }
        }
        
        return -1;
    }
};