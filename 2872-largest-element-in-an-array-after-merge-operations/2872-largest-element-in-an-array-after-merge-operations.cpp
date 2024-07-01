class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {

        int n=nums.size();
        vector<long long> arr(begin(nums),end(nums));
        reverse(begin(arr),end(arr));
        long long ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] >= arr[i+1])
            arr[i+1]=arr[i+1]+arr[i];

            ans=max(arr[i+1],ans);
        }
        return max(ans,arr[0]);

    }
};