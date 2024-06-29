class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n=nums.size();
        int totalsubsets= 1<<n;

        vector<vector<int>> ans;
        for(int i=0;i<totalsubsets;i++)
        {
            vector<int> temp;
            for(int j=0;j<n;j++)
            {
                if(i & 1<<j)
                temp.push_back(nums[j]);
            }
            sort(begin(temp),end(temp));
            ans.push_back(temp);
        }
        sort(begin(ans),end(ans));
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};