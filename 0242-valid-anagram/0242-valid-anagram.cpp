class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size())
        return false;

        sort(begin(s),end(s));
        sort(begin(t),end(t));

        for(int i=0;i<s.size();i++)
        {
            if(s[i] != t[i])
            return false;
        }
        return true;
        
    }
};