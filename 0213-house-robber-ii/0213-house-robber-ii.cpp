class Solution {
public:
    int solve(int i,int n,vector<int> &nums,vector<int> &dp)
    {
        if(i > n)
        return 0;
        if(dp[i] != -1)
        return dp[i];
        int notpick=solve(i+1,n,nums,dp);
        int pick=nums[i]+solve(i+2,n,nums,dp);
        return dp[i]=max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        vector<int> dp2(n,-1);
        return max(solve(0,n-2,nums,dp),solve(1,n-1,nums,dp2));
        
    }
};