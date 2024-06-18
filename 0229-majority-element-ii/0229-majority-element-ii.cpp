class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int ele1,count1=0,count2=0,ele2;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(count1 == 0 && ele2!=nums[i])
            {
                ele1=nums[i];
                count1++;
            }
            else if(count2== 0 && ele1!=nums[i])
            {
                ele2=nums[i];
                count2++;
            }
            else if( nums[i] == ele1)
                count1++;
            else if(nums[i] == ele2)
                count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        
        
        count1=0,count2=0;
        for(auto it: nums)
        {
            if(it == ele1) count1++;
            else if(it == ele2) count2++;
        }
        int mini= (int)(n/3)+1;
        if(count1 >=mini)
        ans.push_back(ele1);
        if(count2 >=mini)
        ans.push_back(ele2);
        return ans;
        
    }
};