class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        while(word1.size()>0 && word2.size()>0){
            if(word1>=word2){
                ans+=word1[0];
                word1.erase(word1.begin());
            }
            else{
                ans+=word2[0];
                word2.erase(word2.begin());
            }
        }
        if(!word1.empty()){
            ans+=word1;
        }
        if(!word2.empty()){
            ans+=word2;
        }
        return ans;
    }
};