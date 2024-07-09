class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& nums) {
        
        int n=nums.size();
        double waiting_time=0;
        int lastprepared=nums[0][0]+nums[0][1];
        waiting_time=nums[0][1];
        for(int i=1;i<n;i++)
        {
            if(nums[i][0] <= lastprepared)
            {
                lastprepared+=nums[i][1];
                waiting_time+=lastprepared - nums[i][0];
            }
            else 
            {
                waiting_time+=nums[i][1];
                lastprepared=nums[i][0]+nums[i][1];
            }
        }

        return waiting_time/n;
    }
};