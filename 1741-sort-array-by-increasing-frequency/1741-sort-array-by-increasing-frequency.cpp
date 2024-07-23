class Solution {
public:
    struct Comp{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)
    {
        return a.first>b.first || (a.first==b.first && a.second<b.second);
    }
    };
    vector<int> frequencySort(vector<int>& nums) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,Comp> pq;
        unordered_map<int,int> mp;
        for(auto it:nums)
        mp[it]++;

        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        int j=0;
        while(!pq.empty())        
        {
            int freq=pq.top().first;
            int ele=pq.top().second;
            pq.pop();
            for(int i=0;i<freq;i++)
            {
                nums[j++]=ele;
            }
        }
        return nums;
    }
};