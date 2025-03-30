class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int k) {
        vector<int> arr(nums.size()+1, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i+1] += arr[i];
            arr[i+1] += nums[i];
        }
        int ans = 0;
        unordered_set<int> s, zero;
        s.insert(0);
        for (int i=0; i!=nums.size(); i++)
        {
            if (s.count(arr[i+1] - k) != 0)
            {
                ans++;
                s = zero;
                s.insert(arr[i+1]);
            }
            else
            {
                s.insert(arr[i+1]);
            }
        }
        return ans;
    }
};