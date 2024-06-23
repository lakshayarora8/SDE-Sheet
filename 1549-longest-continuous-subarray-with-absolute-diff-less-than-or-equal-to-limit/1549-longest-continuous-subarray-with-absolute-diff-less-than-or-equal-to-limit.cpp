class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n=nums.size();

        int i=0,j=0,ans=1;
        multiset<int> st;
  
        while(j<n)
        {
            st.insert(nums[j]);
            auto mini=st.begin();
            auto maxi=st.rbegin();

            if( *(maxi) - *(mini) <= limit)
                ans=max(ans,j-i+1);
            else
                st.erase(st.find(nums[i++]));
            j++;
        }

        return ans;

        
    }
};