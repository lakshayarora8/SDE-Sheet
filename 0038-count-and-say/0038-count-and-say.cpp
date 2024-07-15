class Solution {
public:
    string countAndSay(int n) {
        
        string ans="1";
        string temp="";
        while(--n)
        {
            int size=ans.size();
            int i=0,count=1;
            while(i<size)
            {
                while(i+1<size && ans[i]==ans[i+1])
                {
                    count++;
                    i++;
                }
                temp+=to_string(count);
                temp+=ans[i];
                i++;
                count=1;
            }
            ans=temp;
            temp="";
        }
        return ans;
    }
};