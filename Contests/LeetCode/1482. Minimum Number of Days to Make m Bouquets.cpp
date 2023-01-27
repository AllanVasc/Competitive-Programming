class Solution {
    bool check(vector<int>& v, long long days, int m, int k){
        int curr = 0;
        int answ = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i] <= days){
                curr++;
            }
            else{
                curr = 0;
            }
            if(curr >= k){
                answ++;
                curr = 0;
            }
        }
        
        return (answ >= m);
    }
    
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long answ = -1;
        long long l = 0;
        long long r = 1e9 + 5;
        while(l <= r){
            long long mid = l + (r-l)/2;
            
            if(check(bloomDay, mid, m, k)){
                answ = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return (int) answ;
    }
};