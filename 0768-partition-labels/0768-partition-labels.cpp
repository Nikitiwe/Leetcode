class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> pairs;
        vector<int> lans, ans;
        int l=0, r;
        while (l<=s.size()-1)
        {
            r=s.size()-1;
            while (r>=l)
            {
                if (s[l]==s[r]) {pairs.push_back({l, r}); break;}
                else r--;
            }
            l++;
        }
        l=0;
        r=pairs[0][1];
        while (l<=s.size()-1)
        {
            while (l<r)
            {
                l++;
                if (pairs[l][1]>r) r=pairs[l][1];
            }
            lans.push_back(l);
            l++;
            if (l==s.size()) break;
            r=pairs[l][1];
        }
        ans.push_back(lans[0]+1);
        for (int i=1; i!=lans.size(); i++)
        {
            ans.push_back(lans[i]-lans[i-1]);
        }
        return ans;
    }
};