class Solution {
public:

    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
        if(i<0 && j<0)
        return true;
        if(i>=0 && j<0)
        return false;
        if(i<0 && j>=0)
        {
        for(int k=0;k<=j;k++)
        {
              if(t[k] != '*')
             return false;
        }
      
        return true;
        }
        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == t[j] || t[j]=='?')
        {
            return dp[i][j]= solve(i-1,j-1,s,t,dp);
        }
        if(t[j] == '*')
        return dp[i][j]= solve(i,j-1,s,t,dp) || solve(i-1,j,s,t,dp);

        return dp[i][j]= false;

    }

    bool isMatch(string s, string t) {
        
        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,s,t,dp);
        
    }
};