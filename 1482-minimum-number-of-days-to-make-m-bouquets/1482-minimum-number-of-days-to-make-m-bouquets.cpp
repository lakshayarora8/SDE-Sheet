class Solution {
public:
    
    bool bouquet(int days,vector<int>& nums, int m, int k)
    {
        int adj=k;
        int flowers=0;
        for(int i=0;i<nums.size();i++)
        {
            if(days >= nums[i])
            {
                adj--;
                if(adj == 0)
                {
                    flowers++;
                    adj=k;
                }
            }
            else
            {
                adj=k;
            }
            
        }
        return flowers>=m;
        
    }
    
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int start=INT_MAX,end=INT_MIN;
        
        for(auto it: bloomDay)
        {
            start=min(start,it);
            end=max(end,it);
        }
        
        int mid,res=-1;
        
        while(start<=end)
        {
            mid= (start+end)/2;
            
            if( bouquet(mid,bloomDay,m,k) == true)
            {
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return res;
        
    }
};