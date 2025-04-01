class Solution {
public:
    vector<int> pathInZigZagTree(int k) {
        vector<int> ans;
        int s = 1;
        while (s*2 <= k) s *= 2;
        while (k > 0)
        {
            ans.push_back(k);
            int d = k - s;
            k = s - d/2 - 1;
            s /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};