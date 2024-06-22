class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
            sum++;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};