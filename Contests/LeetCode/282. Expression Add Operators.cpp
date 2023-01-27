// Time Complexity: O(4^N)
// Space Complexity: O(N)

#define ll long long
class Solution {
    vector<string> answ;
    string num;
    int target;
public:
    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        vector<string> x;
        bt(0,0,0,0, x);
        return answ;
    }
private:
    void bt(ll idx, ll total, ll curr_num, ll prev_num, vector<string> &s){
        //cout << "estado atual: " << s << " total = " << total << " curr = " << curr_num << " prev = " << prev_num << '\n';
        if(idx == num.size()){
            if(total == target && curr_num == 0) { 
                string ans = "";
                for (const string &ss : s)
                    ans += ss;
                answ.push_back(ans);
            }
        }
        else{
            curr_num = curr_num*10 + (num[idx]-'0');
            
            if(curr_num > 0){ // I have the option to continue building my current number
                bt(idx+1, total, curr_num, prev_num, s);
            }
            if(s.size() != 0){  // i can make the operations
                s.push_back("+" + to_string(curr_num) );
                bt(idx+1, total + curr_num, 0, curr_num, s);
                s.pop_back();
                
                s.push_back("-" + to_string(curr_num) );
                bt(idx+1, total - curr_num, 0, -curr_num, s);
                s.pop_back();
                
                s.push_back("*" + to_string(curr_num) );
                bt(idx+1, curr_num*prev_num+(total-prev_num), 0, curr_num*prev_num, s);
                s.pop_back();
            }
            else{   // I end my current number
                s.push_back(to_string(curr_num));
                bt(idx+1, total+curr_num, 0, curr_num, s);
                s.pop_back();
            }
        }
    }
};