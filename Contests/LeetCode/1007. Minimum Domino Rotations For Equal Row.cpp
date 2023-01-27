class Solution {

long long solve(int number, vector<int>& tops, vector<int>& bottoms){
    
    long long answ = LONG_LONG_MAX;
    long long curr = 0;
    for(int i = 0; i < tops.size(); i++){
        if(tops[i] != number){
            if(bottoms[i] == number){
                curr++;
            }
            else{
                curr = LONG_LONG_MAX;
                break;
            }
        }
    }
    
    answ = min(answ, curr);
    curr = 0;
    for(int i = 0; i < bottoms.size(); i++){
        if(bottoms[i] != number){
            if(tops[i] == number){
                curr++;
            }
            else{
                curr = LONG_LONG_MAX;
                break;
            }
        }
    }
    
    answ = min(answ, curr);
    return answ;
}
    
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        long long answ = LONG_LONG_MAX;
        int n = tops.size();
        
        answ = min(solve(tops[0], tops, bottoms), solve(bottoms[0], tops, bottoms));

        
        if(answ == LONG_LONG_MAX) return -1;
        else return answ;
    }
};