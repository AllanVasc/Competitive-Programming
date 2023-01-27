class Solution {
public:
    double myPow(double x, int n) {
        
        long double answ = 1;
        long double xx = x;
        long long y = n;
        
        if(y < 0){
            xx = 1.0/xx;
            y = -1*y;
        }
        if(xx == 0) return 0;
        
        while(y){
            if(y & 1) answ = (answ*xx);
            y = y >> 1;
            xx = (xx*xx);
        }
        
        return answ;
    }
};