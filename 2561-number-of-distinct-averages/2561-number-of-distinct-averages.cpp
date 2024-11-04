class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<double> m;
        for (int i=0; i<nums.size()/2; i++)
        {
            m.insert(double(nums[i]+nums[nums.size()-1-i])/2);
        }
        return m.size();
    }
};