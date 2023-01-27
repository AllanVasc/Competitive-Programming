class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> answ;
        int m = mat.size();
        int n = mat[0].size();
        
        int i = 0;
        int j = 0;
        bool up = 1;
        while(answ.size() != m*n){
            answ.push_back(mat[i][j]);
            if(up){
                if(i > 0 && j != n-1){
                    i--;
                    j++;
                }
                else{
                    if(j != n-1) j++;
                    else i++;
                    up = !up;
                }
            }
            else{
                if(j > 0 && i != m-1){
                    j--;
                    i++;
                }
                else{
                    if(i != m-1) i++;
                    else j++;
                    up = !up;
                }
            }
        }
        return answ;
    }
};