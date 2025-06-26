class Solution {
public:
    int longestSubsequence(string s, int kk) {
        int ans = 0;
        for (int k=0; k<s.size(); k++)
        {
            long t = 0;
            int l = 0;
            for (int i=0; i<k; i++)
            {
                if (s[i] == '0') l++;
            }
            for (int i=k; i<s.size(); i++)
            {
                t *= 2;
                if (s[i] == '1') t++;
                l++;
                if (t <= kk)
                {
                    ans = max(ans, l);
                }
                else break;
            }
        }
        return ans;
    }
};