class Solution {
public:
    vector<vector<int>> ans;

    void solve(int ind,vector<int>& nums, int target,vector<int> &ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }
        
       for(int i=ind;i<nums.size();i++)
       {
            if(i>ind && nums[i] == nums[i-1])continue;

            if(nums[i] > target) break;
            ds.push_back(nums[i]);
            solve(i+1,nums,target-nums[i],ds);
            ds.pop_back();
            
       }
    }


    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        vector<int> ds;
        sort(begin(nums),end(nums));
        solve(0,nums,target,ds);
        return ans;
    }
};