class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> diff;
        
        int n = emails.size();
        for(int i = 0; i < n; i++){
            string curr_email = emails[i];
            string curr_local_name;
            string curr_domain;
            bool plus_found = false;
            bool arroba_found = false;
            
            for(int j = 0; j < curr_email.size(); j++){
                if(curr_email[j] == '@'){
                    arroba_found = true;
                    continue;
                }
                if(plus_found == false && arroba_found == false){
                    if(curr_email[j] == '+') plus_found = true;
                    else if(curr_email[j] != '.') curr_local_name.push_back(curr_email[j]);
                }
                if(arroba_found == true){
                    curr_domain.push_back(curr_email[j]);
                }
            }
            
            cout << curr_local_name << '\n';
            cout << curr_domain << '\n';
            diff.insert(curr_local_name + '@' + curr_domain);
        }
        
        return diff.size();
    }
};