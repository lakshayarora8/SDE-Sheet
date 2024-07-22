class Solution {
public:
    int thirdMax(vector<int>& nums) {

        set<int> unique(begin(nums),end(nums));
        priority_queue<int,vector<int>,greater<int>> pq;
        int maxi=INT_MIN;
        for(auto it: unique)
        {
            pq.push(it);
            if(pq.size() >3)
            pq.pop();
            maxi=max(maxi,it);
        }
        if(pq.size() == 3)
        return pq.top(); 
        else
        return maxi;
    }
};