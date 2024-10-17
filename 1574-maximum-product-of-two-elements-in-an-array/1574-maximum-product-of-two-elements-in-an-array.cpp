class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size()>=4) return max({(nums[0]-1)*(nums[1]-1), (nums[1]-1)*(nums[2]-1), (nums[2]-1)*(nums[3]-1), (nums[nums.size()-4]-1)*(nums[nums.size()-3]-1), (nums[nums.size()-3]-1)*(nums[nums.size()-2]-1), (nums[nums.size()-2]-1)*(nums[nums.size()-1]-1)});
        else if (nums.size()==3) return max({(nums[0]-1)*(nums[1]-1), (nums[1]-1)*(nums[2]-1)});
        else return (nums[0]-1)*(nums[1]-1);
    }
};