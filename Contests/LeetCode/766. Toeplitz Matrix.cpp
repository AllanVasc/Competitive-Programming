class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        for(int i = 0; i < matrix[0].size(); i++){
            int aux = matrix[0][i];
            for(int j = 0, k = i; j < matrix.size() && k < matrix[0].size(); j++,k++){
                if(matrix[j][k] != aux) return false;
            }
        }
        
        for(int i = 1; i < matrix.size(); i++){
            int aux = matrix[i][0];
            for(int j = i, k = 0; j < matrix.size() && k < matrix[0].size(); j++,k++){
                if(matrix[j][k] != aux) return false;
            }
        }
        
        return true;
    }
};