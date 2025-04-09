class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> s;
        for (int i=0; i!=nums.size(); i++)
        {
            if (s[nums[i]] == 1) ans ^= nums[i];
            s[nums[i]]++;
        }
        return ans;
    }
};