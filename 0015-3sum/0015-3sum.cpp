class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>> ans;
        sort(begin(nums),end(nums));
        for(int i=0;i<n-1;i++)
        {
            int start=i+1;
            int end=n-1;
            if(i>0 && nums[i] == nums[i-1])
            continue;
            while(start < end)
            {
                if(nums[start] + nums[end] +nums[i] == 0)
                {
                    ans.push_back({nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while(start<end && nums[start] == nums[start-1])
                    start++;
                    while(start<end && nums[end] == nums[end+1])
                    end--;
                }
                else if(nums[start] + nums[end] +nums[i] < 0)
                {
                    start++;
                }
                else
                end--;
            }
           
        }
        return ans;
        
    }
};