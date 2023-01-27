class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int l = 0;
        int r = points.size()-1;
        int pivotIdx = points.size();
        
        while(pivotIdx != k){
            pivotIdx = partition(points,l,r);
            if(pivotIdx < k)
                l = pivotIdx;
            else
                r = pivotIdx - 1;
        }
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    int dist(vector<int>& point){
        return point[0]*point[0] + point[1]*point[1];
    }
    
    int partition(vector<vector<int>>& points, int l, int r){
        
        vector<int>& pivot = points[l + (r-l)/2];
        int pivotDist = dist(pivot);
        
        while(l < r){
            if(dist(points[l]) >= pivotDist){
                swap(points[l], points[r]);
                r--;
            }
            else
                l++;
        }
        
        if(dist(points[l]) < pivotDist)
            l++;
        
        return l;
    }
      
};

/*

Soluções possíveis:

1ª - Classica, usando sort. O(n*logn)
2ª - Usando Max Heap. O(nlogk)
3ª - Binary Search. O(n)
4ª - QuickSelect. O(n)

Obs.: No Worst Case QuickSelect roda em O(n^2), mas igual ao algoritmo do QuickSort iremos assumir que
a maioria dos casos vai rodar em QuickSelect 

*/