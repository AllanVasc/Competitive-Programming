class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int answ = 0;
        int l = 0;
        unordered_map<int,int> freq;
        
        for(int r = l; r < n; r++){
            if(freq.size() == 2 && freq.count(fruits[r]) == 0){ // Need to remove
                // cout << "l = " << l << " r = " << r << '\n';
                while(freq.size() == 2){
                    freq[fruits[l]]--;
                    if(freq[fruits[l]] == 0){
                        freq.erase(fruits[l]);
                    }
                    l++;
                }
                // cout << "ajeitei para: " << "l = " << l << " r = " << r << '\n';
            }
            freq[fruits[r]]++;
            answ = max(answ, r - l + 1);
        }
        return answ;
    }
};