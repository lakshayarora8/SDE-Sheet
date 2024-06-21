class Solution {
public:
    string reverseWords(string s) {
        
        stack<string> st;
        string str="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i] != ' ')
            {
                str="";
                while(i<n && s[i]!=' ')
                {
                    str.push_back(s[i]);
                    i++;
                }
                st.push(str);
            }
        }
        str="";
        while(!st.empty())
        {
            str+=st.top()+" ";
            st.pop();
        }
        str.pop_back();
        return str;
        
    }
};