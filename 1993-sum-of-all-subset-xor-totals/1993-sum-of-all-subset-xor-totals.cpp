class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> prev, next;
        prev.push_back(0);
        next.push_back(0);
        int ans = 0;
        for (int i=0; i<nums.size(); i++)
        {
            for (int j = 0; j!=prev.size(); j++)
            {
                next.push_back(prev[j]^nums[i]);
            }
            prev = next;
        }
        for (int i=0; i!=next.size(); i++) ans += next[i];
        return ans;
    }
};