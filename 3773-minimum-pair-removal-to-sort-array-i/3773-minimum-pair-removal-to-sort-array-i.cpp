bool isdecr(vector<int>& nums)
{
    for (int i=1; i<nums.size(); i++) if (nums[i-1] > nums[i]) return 0;
    return 1;
}

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while (1)
        {
            if (isdecr(nums) == 1) return ans;
            int id = 0;
            for (int i=0; i+1<nums.size(); i++)
            {
                if (nums[i] + nums[i+1] < nums[id] + nums[id+1]) id = i;
            }
            vector<int> t;
            for (int i=0; i<id; i++) t.push_back(nums[i]);
            t.push_back(nums[id] + nums[id+1]);
            for (int i=id+2; i<nums.size(); i++) t.push_back(nums[i]);
            nums = t;
            ans++;
        }
        return -1;
    }
};