class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> arr(100001, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[nums[i] + 50000]++;
        }
        int l = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            while (arr[l] == 0) l++;
            nums[i] = l - 50000;
            arr[l]--;
        }
        return nums;
    }
};