class Solution {
public:
    bool check(vector<int>& nums) {
        int mi=*min_element(nums.begin(), nums.end());
        bool isit=0;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==mi)
            {
                isit=1;
                for (int j=0; j<nums.size()-1; j++)
                if (nums[(i+j)%nums.size()]>nums[(i+j+1)%nums.size()])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) return 1;
        }
        return 0;
    }
};