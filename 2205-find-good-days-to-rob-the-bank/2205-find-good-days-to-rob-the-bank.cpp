class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        int up=0, down=0;
        vector<int> ans, a(s.size(), 0);
        if (t==0) a[0]=2;
        for (int i=1; i!=s.size(); i++)
        {
            if (s[i]<=s[i-1]) down++;
            else down=0;
            if (down>=t) a[i]++;
        }
        for (int i=1; i!=s.size(); i++)
        {
            if (s[i]>=s[i-1]) up++;
            else up=0;
            if (up>=t) a[i-t]++;
        }
        for (int i=0; i!=s.size(); i++)
        {
            if (a[i]==2) ans.push_back(i);
        }
        return ans;
    }
};