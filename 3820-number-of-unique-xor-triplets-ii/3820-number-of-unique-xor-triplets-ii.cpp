class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s; // ксор пар
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=i; j<nums.size(); j++) s.insert(nums[i] ^ nums[j]);
        }
        vector<bool> arr(2048, 0);
        for (int i=0; i!=nums.size(); i++)
        {
            for (int j=0; j!=arr.size(); j++)
            {
                if (arr[j] == 0)
                {
                    if (s.count(j ^ nums[i]) == 1)
                    {
                        arr[j] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for (int j=0; j!=arr.size(); j++) if (arr[j] == 1) ans++;
        return ans;
    }
};