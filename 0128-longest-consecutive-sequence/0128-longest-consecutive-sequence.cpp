class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int,int> mp;
        int n=nums.size();
        for(auto it: nums)
        {
            mp[it]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]-1) == mp.end())
            {
                int count=0;
                while(i<n && mp.find(nums[i]+count) != mp.end())
                {
                    count++;
                    ans=max(ans,count);
                }
            }
        }
        return ans;
        
    }
};