// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution {
public:
    string simplifyPath(string path){
        string answ;
        vector<string> v;
        
        stringstream test(path);
        string segment;
        vector<string> list;

        while(getline(test, segment, '/')){
           list.push_back(segment);
        }
        
        for(int i = 0; i < list.size(); i++){
            if(list[i] == "" || list[i] == "." ) continue;
            else if(list[i] == ".."){
                if(v.size() != 0) v.pop_back();
            }
            else{
                v.push_back(list[i]);
            }
        }
        
        for(int i = 0; i < v.size(); i++){
            answ += "/" + v[i];
        }
        
        return answ.size() > 0 ? answ: "/";
    }
};