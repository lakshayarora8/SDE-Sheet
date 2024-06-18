class Solution {
public:
    double myPow(double x, int n) {
        
        int m=n;
        double ans=1;
        n=abs(n);
        while(n>0)
        {
            if(n&1)
            {
                n--;
                ans*=x;
            }
            else
            {
                n/=2;
                x*=x;
            }
        }
        if(m<0)
            return 1*1LL/ans;
        else
            return ans;
    }
};