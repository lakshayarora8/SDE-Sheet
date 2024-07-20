class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        
        int n=nums.size();
        long long ans=nums[n-1],sum=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {   
            if(sum >= nums[i])
            {
                sum+=nums[i];
            }
            else
            {
                ans=max(ans,sum);
                sum=nums[i];
            }
        }
        return max(sum,ans);
        
    }
};