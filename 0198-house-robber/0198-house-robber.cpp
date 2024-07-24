class Solution {
public:
    int ans=INT_MIN;
    int solve(int i,vector<int> &nums,vector<int> &dp)
    {
        int n=nums.size();
        if( i >= n)
        {
            return 0;
        }   
        if(dp[i] != -1)
        return dp[i];

        //Does not rob
        int leave=solve(i+1,nums,dp);
        //Robs
        int rob=nums[i]+solve(i+2,nums,dp);
        return dp[i]=max(leave,rob);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
        
    }
};