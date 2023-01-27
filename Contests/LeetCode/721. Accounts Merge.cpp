class Solution {
    vector<int> parent;
    vector<int> size;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        build(n);
        map<string,int> mp;
        
        for(int i = 0; i < n; i++){ // Merging
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mp.find(email) == mp.end()){
                    mp[email] = i;
                }
                else{
                    if(find(mp[email]) != i){
                        Union(find(mp[email]), i);
                    }
                }
            }
        }
        
        vector<set<string>> v;
        v.assign(n, set<string>());
        
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                v[find(i)].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> answ;
        
        for(int i = 0; i < n; i++){
            vector<string> aux;
            if(v[i].size() != 0){
                aux.push_back(accounts[i][0]);
                for(auto itr : v[i]){
                    aux.push_back(itr);
                }
                answ.push_back(aux);
            }
        }
        
        return answ;
    }
    
private:
    void build(int n){
        parent.assign(n,0);
        size.assign(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        }
    }
};

// OU

class Solution {
    vector<int> parent;
    vector<int> size;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        build(n);
        map<string,int> mp;
        
        for(int i = 0; i < n; i++){ // Merging
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(mp.find(email) == mp.end()){
                    mp[email] = i;
                }
                else{
                    if(find(mp[email]) != i){
                        Union(find(mp[email]), i);
                    }
                }
            }
        }
        
        map<int, vector<string>> v;
        for(auto itr: mp){
            string email = itr.first;
            int idx = itr.second;
            v[find(idx)].push_back(email);
        }
        
        vector<vector<string>> answ;
        
        for(auto itr : v){
            int idx = itr.first;
            vector<string> aux(1,accounts[idx][0]);
            aux.insert(aux.end(), itr.second.begin(), itr.second.end());
            sort(aux.begin()+1, aux.end());
            answ.push_back(aux);
        }

        
        return answ;
    }
    
private:
    void build(int n){
        parent.assign(n,0);
        size.assign(n,0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a,b);
        parent[b] = a;
        size[a] += size[b];
        }
    }
};