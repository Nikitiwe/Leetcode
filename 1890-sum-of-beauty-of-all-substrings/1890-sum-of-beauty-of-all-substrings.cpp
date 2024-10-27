class Solution {
public:
    int beautySum(string s) {
        vector<vector<int>> arr(s.size()+1, vector<int> (26, 0));
        vector<int> t(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            t[s[i]-'a']++;
            arr[i+1]=t;
        }
        int ans=0;
        for (int i=0; i!=arr.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                int mi=500, ma=0;
                for (int a=0; a!=26; a++)
                {
                    int t=arr[i][a]-arr[j][a];
                    ma=max(ma, t);
                    if (t>0) mi=min(mi, t);
                }
                if (mi!=500) ans+=ma-mi;
            }
        }
        return ans;
    }
};