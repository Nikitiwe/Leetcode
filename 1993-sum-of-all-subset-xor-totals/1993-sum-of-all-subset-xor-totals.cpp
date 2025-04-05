class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<int> prev, next, zero;
        prev.push_back(0);
        int ans = 0;
        for (int i=0; i<nums.size(); i++)
        {
            for (int j = 0; j!=prev.size(); j++)
            {
                next.push_back(prev[j]^nums[i]);
                next.push_back(prev[j]);
            }
            prev = next;
            next = zero;
        }
        for (int i=0; i!=prev.size(); i++) ans += prev[i];
        return ans;
    }
};