class SparseVector {
public:
    
    vector<pair<int,int>> v;
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) v.push_back({i,nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        long long answ = 0;
        int i = 0;
        int j = 0;
        
        while(i < v.size() && j < vec.v.size()){
            
            if(v[i].first == vec.v[j].first)
                answ += v[i].second * vec.v[j].second;
            
            if(v[i].first > vec.v[j].first)
                j++;
            else
                i++;
        }
       
        return answ;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);