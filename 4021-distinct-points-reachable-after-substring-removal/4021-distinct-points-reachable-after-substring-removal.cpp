class Solution {
public:
    int distinctPoints(string s, int k) {
        vector<pair<int, int>> arr(s.size() + 1, pair<int, int>({0, 0}));
        int r = 0, u = 0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] == 'U') u++;
            else if (s[i] == 'D') u--;
            else if (s[i] == 'L') r--;
            else r++;
            arr[i+1] = {r, u};
        }
        unordered_set<long> ss;
        for (int i=k; i<arr.size(); i++)
        {
            auto[r1, u1] = arr[i-k];
            auto[r2, u2] = arr[i];
            ss.insert(((long)r2-r1) * 1000000 + (u2-u1));
        }
        return max((int)ss.size(), 1);
    }
};