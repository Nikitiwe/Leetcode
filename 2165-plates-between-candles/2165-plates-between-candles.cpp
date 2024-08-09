class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> arr(s.size(), 0), arl(s.size(), 0);
        int temp=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='*') temp++;
            else
            {
                arr[i]=temp;
                arl[i]=temp;
            }
        }
        temp=0;
        for (int i=0; i!=s.size(); i++)
        {
            temp=max(arr[i], temp);
            arr[i]=temp;
        }
        temp=999999;
        for (int i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='|') temp=min(arl[i], temp);
            arl[i]=temp;
        }
        vector<int> ans(queries.size(), 0);
        for (int i=0; i!=queries.size(); i++)
        {
            ans[i]=max(arr[queries[i][1]]-arl[queries[i][0]], 0);
        }
        return ans;
    }
};