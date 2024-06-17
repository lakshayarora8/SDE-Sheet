class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(begin(intervals),end(intervals));

        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1] >= intervals[i+1][0])
            {
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=max(intervals[i+1][1],intervals[i][1]);
                intervals[i][0]=-1;
            }
        }
        vector<vector<int>> ans;
        for(auto it: intervals)
        {
            if(it[0] == -1)
            continue;
            else
            ans.push_back(it);
        }
        return ans;
        
    }
};