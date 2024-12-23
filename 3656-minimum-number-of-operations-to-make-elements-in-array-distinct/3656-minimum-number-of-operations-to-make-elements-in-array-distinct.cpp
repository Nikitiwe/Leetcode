class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        vector<int> arr(101, 0);
        for (int i=nums.size()-1; i>=0; i--)
        {
            arr[nums[i]]++;
            if (arr[nums[i]]>1) return i/3+1;
        }
        return 0;
    }
};