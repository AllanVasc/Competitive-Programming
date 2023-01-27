class Solution {

int dist(vector<int>& v){
    return v[0]*v[0] + v[1]*v[1];
}
    
int partition(int l, int r, vector<vector<int>>& v){
    // pivot = v[r];
    int i = 0;
    for(int j = 0; j < r; j++){
        if(dist(v[j]) <= dist(v[r])){
            swap(v[i], v[j]);
            i++;
        }
    }
    // cout << l << " " << r << " " << i << '\n';
    swap(v[r], v[i]);
    
    return i;
}

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int l = 0;
        int r = points.size() - 1;

        while(l <= r){
            int curr_len = r - l + 1;
            int candidate = l + rand() % curr_len;
            swap(points[r], points[candidate]);

            int idx_pivo = partition(l, r, points);

            if(idx_pivo == k - 1) break;
            else if(idx_pivo > k-1){
                r =  idx_pivo - 1;
            }
            else{
                l = idx_pivo + 1;
            }

        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};