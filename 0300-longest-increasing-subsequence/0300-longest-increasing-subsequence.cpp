class Solution {
public:

    int solve(int ind,vector<int>& nums,int lastpicked,vector<vector<int>> &dp)
    {
        int n=nums.size();
        if(ind == n )
        return 0;
        // int pick=0,notpick=0;

        if(dp[ind][lastpicked+1] != -1)
        return dp[ind][lastpicked+1];

        int notpick=solve(ind+1,nums,lastpicked,dp);
        int pick=INT_MIN;
        if(lastpicked==-1 || nums[ind] > nums[lastpicked])
        {
            pick= 1 + solve(ind+1,nums,ind,dp);    
        }
        return dp[ind][lastpicked+1]= max(pick,notpick);

    }


    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        return solve(0,nums,-1,dp);
    }
};