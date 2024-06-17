class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        
        vector<int> freq(26,0);
        vector<int> checking(26,0);
        vector<int> ans;
        int count=1;
        for(auto it: s)
        {
            freq[it-'a']++;
        }
        bool complete=false;
        for(int i=0;i<s.size();i++)
        {
            checking[s[i]-'a']++;
            complete=true;
            for(int j=0;j<=i;j++)
            {
                if( checking[s[j]-'a'] != freq[s[j]-'a'])
                {
                    complete=false;
                }
            }
            if(complete == true)
            {
                ans.push_back(count);
                count=1;
            }
            else
            {
                count++;    
            }
            
        }
        
        return ans;
        
    }
};