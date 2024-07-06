class Solution {
public:
    int passThePillow(int n, int time) {
        
        int decider=time /(n-1);
        if( decider % 2 )
        {
            return n- (time%(n-1));
        }
        return 1+time%(n-1);   
    }
};