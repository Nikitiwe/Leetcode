class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        float ans, min;
        ans=(float(nums[0])+float(nums[nums.size()-1]))/2;
        for (int i=1; i!=nums.size()/2; i++)
        {
            min=(float(nums[i])+float(nums[nums.size()-1-i]))/2;
            if (min<ans) ans=min;
        }
        return ans;
    }
};