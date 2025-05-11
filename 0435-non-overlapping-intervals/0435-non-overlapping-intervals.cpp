bool ssort(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), ssort);
        int ans = 0;
        int pa = -100000, pb = -100000;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i][0] < pb && nums[i][1] >= pb) ans++;
            else
            {
                pb = nums[i][1];
            }
        }
        return ans;
    }
};