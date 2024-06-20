class Solution {
public:
    
    bool force(int mid,vector<int>& nums,int m)
    {
        int lastplaced=nums[0];
        int balls=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-lastplaced >= mid)
            {
                balls++;
                lastplaced=nums[i];
                if(balls == m)
                    return true;
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& nums, int m) {
        
        
        sort(begin(nums),end(nums));
        
        int n=nums.size();
        int start=1;
        int end=(nums[n-1]-nums[0])/(m-1);
        
        int res=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            
            if(force(mid,nums,m) == true)
            {
                res=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return res;
        
    }
};