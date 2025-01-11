class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int t=100000;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==1)
            {
                if (t<k) return 0;
                t=0;
            }
            else t++;
        }
        return 1;
    }
};