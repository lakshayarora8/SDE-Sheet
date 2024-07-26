class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st;

        for(auto it: nums)
        st.insert(it);
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i] - 1) == st.end())
            {
                int len=1;
                while(st.find(nums[i] +len) != st.end())
                {
                    len++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};