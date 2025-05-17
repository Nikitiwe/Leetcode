class Solution {
public:
    int minimumAddedInteger(vector<int>& nums, vector<int>& nums2) {
        vector<int> arr(1001, 0);
        for (int i=0; i!=nums2.size(); i++) arr[nums2[i]]++;
        for (int k = -1000; k<=1000; k++)
        {
            vector<int> t(1001, 0);
            for (int i=0; i!=nums.size(); i++) if (nums[i] + k >= 0 && nums[i] + k <= 1000) t[nums[i] + k]++;
            int c = 0;
            for (int i=0; i<t.size(); i++) if (t[i] < arr[i]) c += arr[i] - t[i];
            if (c <= 0) return k;
        }
        return -2025;
    }
};