class Solution {
public:
    long long maximumPoints(vector<int>& energy, int curr) {
        
        long long ans=0;
        long long current=curr;
        int n=energy.size();
        int left=0,right=n-1;
        sort(begin(energy),end(energy));
        // if(energy[0] > current) return 0;
        while(left <= right)
        {
            if(current >= energy[left])
            {
                ans+=current/energy[left];
                current%=energy[left];
            }
            else if(current< energy[left] && ans>0){    
                current+=energy[right];
                right--;
            }
            else
                break;
        }
        return ans;
        
    }
};