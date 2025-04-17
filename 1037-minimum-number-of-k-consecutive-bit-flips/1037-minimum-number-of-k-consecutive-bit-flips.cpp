class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int> add(nums.size() + 1, 0);
        int ans = 0;
        int t = 0;
        for (int i=0; i!=nums.size(); i++)
        {
            t += add[i];
            if (nums[i] == (t%2) )
            {
                ans++;
                t++;
                if (i+k < add.size()) add[i+k]--;
                else return -1;
            }
        }
        return ans;
    }
};