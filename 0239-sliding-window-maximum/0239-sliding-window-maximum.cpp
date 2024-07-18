class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {


        int i=0,j=0,n=nums.size();
        vector<int> ans;
        multiset<int> st;
        while(j<n)
        {
            st.insert(nums[j]);
            if(j-i+1 == k)
            {
                ans.push_back(*st.rbegin());
                auto it=st.find(nums[i]);
                st.erase(it);
                i++;
            }
            j++;
        }
        return ans;
        
    }
};