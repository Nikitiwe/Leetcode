class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> u, d;
        u.push_back(nums[0]);
        d.push_back(nums[1]);
        for (int i=2; i<nums.size(); i++)
        {
            if (u[u.size()-1]>d[d.size()-1]) u.push_back(nums[i]);
            else d.push_back(nums[i]);
        }
        for (int i=0; i!=u.size(); i++) nums[i]=u[i];
        for (int i=0; i!=d.size(); i++) nums[nums.size()-1-i]=d[d.size()-1-i];
        return nums;
    }
};