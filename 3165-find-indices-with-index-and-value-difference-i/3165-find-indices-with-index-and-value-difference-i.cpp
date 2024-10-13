class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int iD, int vD) {
        if (iD>nums.size()) return {-1, -1};
        for (int i=0; i<nums.size()-iD; i++)
        {
            for (int j=i+iD; j<nums.size(); j++)
            {
                if (abs(nums[i]-nums[j])>=vD) return {i, j};
            }
        }
        return {-1, -1};
    }
};