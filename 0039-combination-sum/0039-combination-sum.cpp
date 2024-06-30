class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index,vector<int>& nums, int target, vector<int> &ds)
    {
        if( index == nums.size())
        {
            if(target == 0)
            ans.push_back(ds);
            return;
        }
        if(nums[index] <= target)
        {
            ds.push_back(nums[index]);
            solve(index,nums,target-nums[index],ds);
            ds.pop_back();
        }
        solve(index+1,nums,target,ds);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> ds;
        solve(0,candidates,target,ds);
        return ans;
    }
};