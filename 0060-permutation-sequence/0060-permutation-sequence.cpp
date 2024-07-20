class Solution {
public:
    vector<int> ans;
    void solve(int index,vector<int> &nums,int &k)
    {
        if(index == nums.size())
        {
            k--;
            if(k==0)
            ans=nums;
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            solve(index+1,nums,k);
            swap(nums[index],nums[i]);
        }
    }

    string getPermutation(int n, int k) {

        vector<int> nums(n,0);

        for(int i=0;i<n;i++)
        nums[i]=i+1;
        k--;
        while(k--)
        next_permutation(nums.begin(),nums.end());

        string temp="";
        for(auto it: nums)
        {
            temp+=to_string(it);
        }
        return temp;
        
    }
};