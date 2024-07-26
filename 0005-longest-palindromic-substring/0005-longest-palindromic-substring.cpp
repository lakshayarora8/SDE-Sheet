class Solution {
public:

    int solve(string &s,int l,int r,vector<vector<int>> &dp)
    {
        if(l>=r) return 1;

        if(dp[l][r] != -1) return dp[l][r];

        if(s[l] == s[r] )
        return dp[l][r]= solve(s,l+1,r-1,dp);

        return dp[l][r]=false;
    }

    string longestPalindrome(string s) { 
        int n=s.size();
        int starting_index=0,maxlength=0;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(solve(s,i,j,dp))
                {
                    if(j-i+1 > maxlength){
                    starting_index=i;
                    maxlength=j-i+1;
                    }
                }
            }
        }

        return s.substr(starting_index,maxlength);
    }
};