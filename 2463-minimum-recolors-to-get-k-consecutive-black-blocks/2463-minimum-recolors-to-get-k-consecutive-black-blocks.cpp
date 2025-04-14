class Solution {
public:
    int minimumRecolors(string s, int k) {
        int sum = 0;
        for (int i=0; i!= k; i++) if (s[i] == 'W') sum++;
        int ans = sum;
        for (int i=k; i<s.size(); i++)
        {
            if (s[i] == 'W') sum++;
            if (s[i-k] == 'W') sum--;
            ans = min(ans, sum);
        }
        return ans;
    }
};