class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        vector<int> arr(nums.size()+1, 0);
        int s=0;
        for (int i=0; i!=nums.size(); i++)
        {
            s+=arr[i];
            if (s>nums[i]) return 0;
            if (i+k<=nums.size()) arr[i+k]-=(nums[i]-s);
            else if (nums[i]!=s) return 0;
            s=nums[i];
        }
        return 1;
    }
};