class Solution {
public:

    int solve(int i,int j,string &s ,string &t,vector<vector<int>> &dp)
    {
        if(j<0)
        return i+1;
        if(i<0)
        return j+1;
        if(dp[i][j] != -1)
        return dp[i][j];
        int notpick=INT_MAX,pick=INT_MAX;
        if( s[i] == t[j])
        pick= solve(i-1,j-1,s,t,dp); 
        else
        {
            int insert=1+solve(i,j-1,s,t,dp);
            int replace=1+solve(i-1,j-1,s,t,dp);
            int del=1+solve(i-1,j,s,t,dp);
            notpick=min(insert,min(replace,del));
        }
        return dp[i][j]= min(pick,notpick);
    }

    int minDistance(string s, string t) {

        int m=s.size();
        int n=t.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(m-1,n-1,s,t,dp);      
    }
};