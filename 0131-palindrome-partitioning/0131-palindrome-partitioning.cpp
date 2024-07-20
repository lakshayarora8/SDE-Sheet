class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;
        solve(s,0,path,ans);
        return ans;
    }

    void solve(string s,int ind,vector<string> &path,vector<vector<string>>&ans)
    {
        if(ind == s.size())
        {
            ans.push_back(path);
            return;
        }

        for(int i=ind;i<s.size();i++)
        {
            if(ispallindrome(s,ind,i))
            {
                string x=s.substr(ind,i-ind+1);
                path.push_back(x);
                solve(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }

    bool ispallindrome(string s,int start,int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
            return false;
        }
        return true;
    }
};