class Solution {
public:
    int compareVersion(string s, string t) {

        int m=s.size();
        int n=t.size();
        int i=0,j=0;
        while(i<m || j<n)
        {
            int v1=0,v2=0;
            while(i<m && s[i] != '.')
            {
                v1*=10;
                v1+=s[i]-'0';
                i++;
            }
            while(j<n && t[j] != '.')
            {
                v2*=10;
                v2+=t[j]-'0';
                j++;
            }
            if(v1>v2)return 1;
            else if(v2>v1) return -1;
            i++;
            j++;
        }
        return 0;
    }
};