class Solution {
public:
    string reverseWords(string s) {
        
        string temp="";
        string ans="";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != ' ')
            {
                temp+=s[i];
            }
            else
            {
                if(temp != "")
                {
                    ans=temp+" "+ans;
                    temp="";
                }
            }
        }
        if(temp != "")
                {
                    ans=temp+" "+ans;
                    temp="";
                }
        ans.pop_back();
        return ans;
        
    }
};