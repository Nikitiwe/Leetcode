class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost(s.size(), 0);
        for (int i=0; i!=s.size(); i++)
        {
            cost[i]=abs(s[i]-t[i]);
        }
        if (s.size()==1)
        {
            if (cost[0]<=maxCost) return 1;
            else return 0;
        }
        int l=0, r=0, temp=cost[0], ans=0;
        if (cost[0]<=maxCost) ans++;
        while (r<s.size()-1)
        {
            if (temp+cost[r+1]<=maxCost) {r++; temp+=cost[r]; ans=max(ans, r-l+1);}
            else
            {
                temp-=cost[l];
                l++;
                if (temp<=maxCost) ans=max(ans, r-l+1);
                if (l>r) {r++; temp=cost[r]; if (temp<=maxCost) ans=max(ans, r-l+1);}
            }
        }
        return ans;
    }
};