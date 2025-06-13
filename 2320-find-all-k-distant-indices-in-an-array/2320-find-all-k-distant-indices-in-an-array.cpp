class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> arr(nums.size(), 0);
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] == key)
            {
                int t = max(0, i-k);
                arr[t]++;
                if (i + k + 1 < arr.size()) arr[i + k + 1] = -1;
            }
        }
        vector<int> ans;
        int t = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            t += arr[i];
            if (t > 0) ans.push_back(i);
        }
        return ans;
    }
};