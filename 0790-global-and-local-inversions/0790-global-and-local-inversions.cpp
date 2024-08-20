class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i=0; i!=nums.size()-1; i++)
        {
            if (nums[i]>i+1) return 0;
            if (nums[i]==i+1&&nums[i+1]!=i) return 0;
        }
        return 1;
    }
};