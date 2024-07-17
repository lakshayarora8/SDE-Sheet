class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() >nums2.size()) 
        return findMedianSortedArrays(nums2,nums1);
        int m=nums1.size(),n=nums2.size();


        int l=0,h=m;

        while(l<=h)
        {
            int px= l+ (h-l)/2;
            int py= (m+n+1)/2 -px;

            int x1=(px == 0) ? INT_MIN :nums1[px-1];
            int x2= (px==m)?INT_MAX:nums1[px];
            int x3= (py == 0) ? INT_MIN: nums2[py-1];
            int x4=(py==n)?INT_MAX:nums2[py];

            if(x1<=x4 && x3<=x2)
            {
                if((m+n)%2 == 0){
                    return (max(x1,x3)+min(x2,x4))/2.0;
                }
                else
                return max(x1,x3);
            }
            else if(x1>x4)
            h=px-1;
            else
            l=px+1;
        } 

        return -1;
    }
};