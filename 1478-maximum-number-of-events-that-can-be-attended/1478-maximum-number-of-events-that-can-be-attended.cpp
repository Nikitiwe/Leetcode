class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int id = 0;
        map<int, int> s;
        for (int t=0; t<=1e5; t++)
        {
            while (id < nums.size() && nums[id][0] <= t)
            {
                s[nums[id][1]]++;
                id++;
            }
            if (s.size() > 0)
            {
                if (s.begin()->first < t) s.erase(s.begin()->first);
                if (s.size() > 0)
                {
                    s[s.begin()->first]--;
                    if (s[s.begin()->first] == 0) s.erase(s.begin()->first);
                    ans++;
                }
            }
            if (id == nums.size() && s.size() == 0) break;
        }
        return ans;
    }
}; // [[1,5],[1,5],[1,5],[2,3],[2,3]]