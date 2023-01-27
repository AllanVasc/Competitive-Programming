// There's a better way using Yale Format!

// Compressing Matriz
// Time Complexity: O(N^3) Worst Case
// Space Complexity: O(M*K + K*N)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int m = mat2[0].size();
        
        vector<vector<int>> answ(n, vector<int>(m, 0));
        
        vector<vector<pair<int,int>>> A = compress(mat1);
        vector<vector<pair<int,int>>> B = compress(mat2);
        
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < A[i].size(); j++){
                
                int A_column = A[i][j].first;
                int A_value = A[i][j].second;
                
                for(int k = 0; k < B[A_column].size(); k++){
                    int B_idx = B[A_column][k].first;
                    int B_value = B[A_column][k].second;;
                    
                    answ[i][B_idx] += A_value * B_value;
                }
            }
        }
        
        return answ;
    }
    
    vector<vector<pair<int,int>>> compress(vector<vector<int>> mat){
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<pair<int,int>>> answ(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != 0) answ[i].push_back({j,mat[i][j]});
            }
        }
        
        return answ;
    }
};

// Naive with optimization
// Time Complexity: O(N^3)
// Space Complexity: (1)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int m = mat2[0].size();
        
        vector<vector<int>> result;
        result.assign(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int k = 0; k < mat1[0].size(); k++){
                
                if(mat1[i][k] != 0){
                    for(int j = 0; j < m; j++){
                        result[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
                
            }
        }
        
        return result;
    }
};

// Naive
// Time Complexity: O(N^3)
// Space Complexity: (1)

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int m = mat2[0].size();
        
        vector<vector<int>> result;
        result.assign(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                for(int k = 0; k < mat1[0].size(); k++){
                    result[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        
        return result;
    }
};