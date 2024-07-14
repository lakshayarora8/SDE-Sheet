class Solution {
public:
    int myAtoi(string s) {
        
        int n=s.size();
        int positive=1;
        long long sum=0;
        bool start=false;
        for(int i=0;i<n;i++)
        {
            if(s[i] != ' ' && !(s[i] >='0' && s[i]<='9') && s[i]!='+' && s[i]!='-')
            break;
            else if(s[i] == ' '){
                 if(start==false)
                 continue;
                 else
                 break;
            }
            else if(s[i] == '-'){
                {
                    if(start==false)
                    positive=-1;
                    else
                    break;
                    start=true;

                }
            }
            else if(s[i] == '+'){
                {
                    if(start==false)
                    positive=1;
                    else
                    break;
                    start=true;


                }
            }
            else
            {
                start=true;
                if(sum>INT_MAX) break;
                sum*=10;
                sum+=s[i]-'0';
            }
        }
        if(sum >INT_MAX)
        {
            if(positive==1)
            return INT_MAX;
            return INT_MIN;
        }

        return positive*(int)sum;
    }
};