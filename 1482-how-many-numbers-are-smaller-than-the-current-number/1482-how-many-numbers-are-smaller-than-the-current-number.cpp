class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> a=nums, ans;
        sort(a.begin(), a.end());
        for (int i=0; i!=nums.size(); i++)
        {
            ans.push_back(distance(a.begin(), find(a.begin(), a.end(), nums[i])));
        }
        return ans;
    }
};