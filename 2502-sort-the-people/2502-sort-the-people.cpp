class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        vector<pair<int,int>> p;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            p.push_back({heights[i],i});
        }
        sort(p.begin(),p.end());
        reverse(begin(p),end(p));
        vector<string> ans(n);

        for(int i=0;i<n;i++)
        {
            ans[i]=names[p[i].second];
        }
        return ans;
    }
};