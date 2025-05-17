class Solution {
public:
    int maxFreeTime(int n, int k, vector<int>& s, vector<int>& e) {
        int ans = 0;
        int sum = 0;
        for (int i=0; i!=k; i++)
        {
            sum += e[i] - s[i];
        }
        if (k < s.size()) ans = max(ans, s[k] - sum);
        else ans = max(ans, n - sum);
        for (int i=k; i<s.size(); i++)
        {
            sum += e[i] - s[i];
            sum -= e[i-k] - s[i-k];
            if (i+1 < s.size()) ans = max(ans, s[i+1] - e[i-k] - sum);
            else ans = max(ans, n - e[i-k] - sum);
        }
        return ans;
    }
};