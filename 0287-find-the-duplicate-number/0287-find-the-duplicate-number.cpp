class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> arr(nums.size(), 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[nums[i]]++;
            if (arr[nums[i]]>1) return nums[i];
        }
        return -1;
    }
};