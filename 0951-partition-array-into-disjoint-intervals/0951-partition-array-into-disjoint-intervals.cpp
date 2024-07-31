class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> arr(nums.size(), 0);
        arr[nums.size()-1]=nums[nums.size()-1];
        for (int i=nums.size()-2; i>=0; i--)
        {
            arr[i]=min(arr[i+1], nums[i]);
        }
        arr[0]=nums[0];
        if (arr[0]<=arr[1]) return 1;
        for (int i=1; i!=nums.size(); i++)
        {
            arr[i]=max(arr[i-1], nums[i]);
            if (arr[i]<=arr[i+1]) return i+1;
        }
        return 0;
    }
};