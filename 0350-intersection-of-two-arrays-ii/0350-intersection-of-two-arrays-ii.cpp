class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp;
        for(auto it: nums2)
        mp[it]++;
        vector<int> ans;
        for(auto it:nums1)
        if(mp[it])
        {
            mp[it]--;
            ans.push_back(it);
        }

        return ans;
        
    }
};