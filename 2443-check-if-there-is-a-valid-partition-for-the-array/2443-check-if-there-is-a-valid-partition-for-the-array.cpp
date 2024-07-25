class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<bool> arr(nums.size(), 0);
        if (nums[0]==nums[1]) arr[1]=1;
        if (nums.size()>2&&nums[0]==nums[1]&&nums[1]==nums[2]) arr[2]=1;
        if (nums.size()>2&&nums[0]+1==nums[1]&&nums[1]+1==nums[2]) arr[2]=1;
        for (int i=3; i<nums.size(); i++)
        {
            if (arr[i-2]==1&&nums[i-1]==nums[i]) arr[i]=1;
            if (arr[i-3]==1&&nums[i-2]==nums[i-1]&&nums[i-1]==nums[i]) arr[i]=1;
            if (arr[i-3]==1&&nums[i-2]+1==nums[i-1]&&nums[i-1]+1==nums[i]) arr[i]=1;
        }
        return arr[nums.size()-1];
    }
};