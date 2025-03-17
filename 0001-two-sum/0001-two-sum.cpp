class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int, int> s;
        for (int i=0; i!=nums.size(); i++)
        {
            if(s.count(t-nums[i]) != 0)
            {
                return {s[t-nums[i]], i};
            }
            s[nums[i]] = i;
        }
        return {-1, -1};
    }
};