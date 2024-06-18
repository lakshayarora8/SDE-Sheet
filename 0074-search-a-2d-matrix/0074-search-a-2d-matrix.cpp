class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        
        int low=0,mid,high=m-1;
        int res=-1;
        
        while(low<=high)
        {
            mid= (low+high)/2;
            
            if(matrix[mid][0] == target)
                return true;
            else if( matrix[mid][0] < target)
            {
                res=mid;
               low=mid+1;
            }
            else
                high=mid-1;
        }
        
        if(res == -1)
            return false;
        low=0,high=n-1;
        
        while(low<=high)
        {
            mid= (low+high)/2;
            
            if(matrix[res][mid] == target)
                return true;
            else if( matrix[res][mid] > target)
            {
               high=mid-1;
            }
            else
                low=mid+1;
        }
        
        return false;
        
        
    }
};