class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        
        int i = 0;
        int j = 0;
        vector<vector<int>> answ;
        
        while(i < encoded1.size() && j < encoded2.size()){
            
            int qtd = min(encoded1[i][1], encoded2[j][1]);
            encoded1[i][1] -= qtd;
            encoded2[j][1] -= qtd;
            
            int prod = encoded1[i][0]*encoded2[j][0];
            if(answ.size() > 0 && answ.back()[0] == prod){
                answ.back()[1] += qtd;
            }
            else{
                answ.push_back({prod, qtd});
            }
            
            if(encoded1[i][1] == 0) i++;
            if(encoded2[j][1] == 0) j++;
        }
        
        return answ;
    }
};