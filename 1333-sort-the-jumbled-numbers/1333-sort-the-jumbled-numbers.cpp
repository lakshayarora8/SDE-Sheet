class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second<b.second;
        return a.first<b.first;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> maped(nums.size());
        for(int i=0;i<nums.size();i++){
            int cur=nums[i],newnum=0; bool flag=false;
            for(int j=9;j>=0;j--){
                int digit=cur/pow(10,j);
                if(!digit && !flag && j!=0) continue;
                flag=true;
                newnum+=(mapping[digit]*pow(10,j));
                cur-=(digit*pow(10,j));
            }
            maped[i].first=newnum;
            maped[i].second=i;
        }
        sort(maped.begin(),maped.end(),cmp);
        vector<int> res(nums.size());
        for(int i=0;i<maped.size();i++){
            res[i]=nums[maped[i].second];
        }
        return res;
    }
};