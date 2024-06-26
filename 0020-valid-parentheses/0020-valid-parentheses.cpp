class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(auto it: s)
        {
            if(it == '(' || it=='[' || it=='{')
            st.push(it);
            else if(!st.empty())
            {
            if(it == ')' && st.top() != '(')
            return false;
            else if(it == ']' && st.top() != '[')
            return false;
            else if(it == '}' && st.top() != '{')
            return false;
            st.pop();
            }
            else
            return false;
        }
        
        return st.empty();
    }
};