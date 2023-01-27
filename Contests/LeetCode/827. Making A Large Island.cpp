// Time Complexity: O(N^2)
// Space Complexity: O(N^2)

class Solution {
    unordered_map<int,int> freq;
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        preprocess(grid);
        
        // cout << "ISLAND: " << '\n';
        // for(int i = 0; i < grid.size(); i++){
        //     for(int j = 0; j < grid.size(); j++){
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << "FREQ = " << '\n';
        // for(auto i : freq){
        //     cout << "ID = " << i.first << " = " << i.second << '\n';
        // }
        return solve(grid);   
    }
    
private:
    void preprocess(vector<vector<int>>& grid){
        int n = grid.size();
        int islandId = 2;
        
        for(int i = 0; i < n; i++){ // Preprocess
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    bfs(grid, {i,j}, islandId);
                    islandId++;      
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>& grid, pair<int,int> start, int islandId){
        
        int n = grid.size();
        queue<pair<int,int>> q;
        q.push(start);
        grid[start.first][start.second] = islandId;
        int len = 0;
        
        vector<pair<int,int>> dir = { {-1,0}, {0,1}, {1, 0}, {0, -1} };
        
        while(!q.empty()){
            pair<int,int> aux = q.front();
            q.pop();
            
            for(auto curr : dir){
                int r = aux.first + curr.first;
                int c = aux.second + curr.second;
                
                if(r >= 0 && c >= 0 && c < n && r < n && grid[r][c] == 1){
                    q.push({r,c});
                    grid[r][c] = islandId;
                }
            }
            len++;
        }
        
        freq[islandId] = len;
    }
    
    int solve(vector<vector<int>>& grid){
        int n = grid.size();
        int answ = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    answ = max(answ, count(grid, {i,j}));
                }
                else{
                    answ = max(answ, freq[grid[i][j]]);
                }
            }
        }
            
        return answ;
    }
    
    int count(vector<vector<int>>& grid, pair<int,int> start){
        int n = grid.size();
        set<int> s;
        vector<pair<int,int>> dir = { {-1,0}, {0,1}, {1, 0}, {0, -1} };
        
        for(auto curr : dir){
            int r = start.first + curr.first;
            int c = start.second + curr.second;

            if(r >= 0 && c >= 0 && c < n && r < n && grid[r][c]){
                s.insert(grid[r][c]);
            }
        }
        
        int answ = 1;
        for(auto i : s){
            answ += freq[i];
        }
        
        return answ;
    }
};