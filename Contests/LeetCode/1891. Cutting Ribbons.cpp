class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1;
        int r = int(1e5 + 10);
        int answ = 0;
        while(l <= r){
            int m = l + (r-l)/2;
            
            if(check(ribbons,k,m)){
                answ = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        return answ;
    }
private:
    bool check(vector<int>& ribbons, int k, int size){
        int answ = 0;
        for(int i = 0; i < ribbons.size(); i++){
            answ += ribbons[i]/size;
        }
        
        if(answ >= k) return true;
        else return false;
    }
};