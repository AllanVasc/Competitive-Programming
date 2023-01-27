// Time Complexity: O(max(N1,N2))
// Space Complexity: O(1)

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string answ;
        int carry = 0;
        int i = num1.size() -1;
        int j = num2.size() - 1;
        
        while(i >= 0 || j >= 0){
            int x1 = 0;
            int x2 = 0;
            if(i >= 0) x1 = num1[i] - '0';
            if(j >= 0) x2 = num2[j] - '0';
            
            answ.push_back((char) (x1+x2+carry)%10 + '0' );
            if(x1 + x2 + carry > 9) carry = 1;
            else carry = 0;
            i--;
            j--;
        }
        
        if(carry == 1){
            answ.push_back(carry + '0');
        }
        
        reverse(answ.begin(), answ.end());
        
        return answ;
    }
};