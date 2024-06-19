class Solution {
public:
    
    bool solve(int index,int target,vector<int>& nums,vector<vector<int>> &dp)
    {
        
        if(target == 0) return true;
        if(index == 0) return nums[0]==target;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool notpick=solve(index-1,target,nums,dp);
        bool pick=false;
        
        if(nums[index] <= target)
            pick=solve(index-1,target-nums[index],nums,dp);
        
        return dp[index][target]=pick | notpick;
        
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum=accumulate(nums.begin(), nums.end(), 0);
        if(sum&1)
        return false;
        int target=sum/2;
        
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,nums,dp);
    
        
    }
};