class Solution {
public:
    int findTheWinner(int n, int k) {

        vector<int> v(n,0);
        for(int i=0;i<n;i++)
        v[i]=i+1;
        int i=0;
        k--;
        while(v.size() != 1)
        {
            int n=v.size();
            int eliminated=(i+k)%n;
            v.erase(v.begin()+(i+k)%n);
            i=eliminated;
        }
        return v[0];
        
    }
};