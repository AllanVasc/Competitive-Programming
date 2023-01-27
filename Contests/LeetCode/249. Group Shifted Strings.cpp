// Time Complexity: O(N*K)
// Space Complexity: O(N*K)

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>>  answ;
        int qtd = 0;
        map<string,int> mp;
        for(int i = 0; i < strings.size(); i++){
            string aux = normalize(strings[i]);
            if(mp.find(aux) == mp.end()){
                mp[aux] = qtd;
                qtd++;
            }
        }
        
        answ.assign(qtd, vector<string>());
        for(int i = 0; i < strings.size(); i++){
            string aux = normalize(strings[i]);
            answ[mp[aux]].push_back(strings[i]);
        }
        return answ;
    }

private:
    string normalize(string& s){
        int norm = s[0] - 'a';
        string answ;
        for(int i = 0; i < s.size(); i++){
            if(s[i] - 'a' - norm >= 0) answ += s[i] - norm;
            else answ += s[i] - norm + 26;
        }
        cout << answ << '\n';
        return answ;
    }
};