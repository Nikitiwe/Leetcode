class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c = 1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i-1] == nums[i])
            {
                c++;
                if (c>2) nums[i-1] = 1000000;
            }
            else c = 1;
        }
        int d = 0, l = 1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] == 1000000)
            {
                d++;
            }
            else
            {
                nums[l] = nums[i];
                l++;
            }
        }
        return nums.size() - d;
    }
};