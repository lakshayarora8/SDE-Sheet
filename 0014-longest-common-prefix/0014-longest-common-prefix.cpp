class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {

        int n=s.size();

        for(int i=0;i<s[0].size();i++)
        {
            int ch=s[0][i];
            bool match=true;
            for(int j=1;j<n;j++)
            {
                if(s[j][i] != ch)
                match=false;
            }
            if(match == false)
            return s[0].substr(0,i);
        }

        return s[0];
        
    }
};