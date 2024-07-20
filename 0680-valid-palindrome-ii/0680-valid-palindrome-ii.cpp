class Solution {
public:
    bool validPalindrome(string s) {

        //  abcdecba    aebcdcba
        int counter=0;
        int start=0,end=s.size()-1;
        while(start <= end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
             else if(s[start+1] == s[end])
            {
                start++;
                counter++;
            }
            else if(s[start] == s[end-1])
            {
                counter++;
                end--;
            }
           
            else
            return false;
            if(counter > 1) return false;
        }
        return true;
    }
};