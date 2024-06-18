class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int majority=nums[0],count=0;
        for(auto it: nums)
        {
            if(it == majority)
                count++;
            else if(count == 0)
            {
                majority=it;
                count=1;
            }
            else
                count--;
        }
        
        return majority;
        
    }
};