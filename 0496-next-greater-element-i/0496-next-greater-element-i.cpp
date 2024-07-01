class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mp;
        vector<int> result( nums1.size(),-1);
        stack<int> st;
        for(auto it:nums2)
        {

            while(!st.empty() && st.top() < it)
            {
                mp[st.top()]=it;
                st.pop();
            }
            st.push(it);
        }

        for(int i=0;i<nums1.size();i++)
        {
            if(mp[nums1[i]])
            result[i]=mp[nums1[i]];
        }

        return result;
    }
};