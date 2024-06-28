class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n=nums.size();
        int start=0,end=n-1;
        while(start<=end)
        {
            int mid= start + (end-start)/2;

            if(start == end)
            return nums[start];

            if(mid+1<n && mid-1>=0 && nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
            return nums[mid];
            else if( mid%2==1 && nums[mid]==nums[mid-1])
                start=mid+1;
            else if( mid%2==0 && nums[mid]==nums[mid+1])
                 start=mid+1;
            else
                end=mid-1;
        }
        return nums[start];
        
    }
};