class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int n=grumpy.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i] == 0)
            {
                sum+=customers[i];
            }
        }
        
        int i=0,j=0;
        int normalsum=0,specialsum=0;
        int answer=0,newsum;
        
        int k=minutes;
        
        for(int i=0;i<k;i++)
        {
             if(grumpy[i] == 0) normalsum+=customers[i];
             specialsum+=customers[i];
        }
        
         newsum=sum-normalsum+specialsum;
         answer=max(sum,newsum);

        for(int i=k;i<n;i++)
        {
             if(grumpy[i-k] == 0)
             normalsum-=customers[i-k];   
             specialsum-=customers[i-k];

             if(grumpy[i] == 0)
             normalsum+=customers[i];    
             specialsum+=customers[i];
            
             newsum=sum-normalsum+specialsum;
             answer=max(answer,newsum);
        }
 
        return answer;
      
    }
};