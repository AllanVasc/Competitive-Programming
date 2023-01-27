// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> freq;
        stack<int> st;
        int last_time = 0;
        
        freq.assign(n,0);
        
        for(int i = 0; i < logs.size(); i++){
            int points = 0;
            int current_idx = 0;
            int current_time = 0;
            string command = "";
            
            for(int j = 0; j < logs[i].size(); j++){ // Read command
                if(logs[i][j] == ':') points++;
                else if(points == 1){
                    command += logs[i][j];
                }
                else if(points == 0){
                    current_idx = current_idx*10 + logs[i][j] - '0';
                }
                else if(points == 2){
                    current_time = current_time*10 + logs[i][j] - '0';
                }
            }
            
            if(command == "start"){
                if(!st.empty()){
                    int last_idx = st.top();
                    freq[last_idx] += (current_time - last_time);
                }
                st.push(current_idx);
                last_time = current_time;
            }
            else{
                freq[current_idx] += (current_time + 1 - last_time);
                st.pop();
                last_time = current_time + 1;
            }
        }
        
        return freq;
    }
};