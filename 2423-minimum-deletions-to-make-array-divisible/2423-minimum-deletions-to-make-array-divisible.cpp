class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        bool isit;
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (i>0&&nums[i]==nums[i-1]) ans++;
            else
            {
                isit=0;
                for (int j=0; j!=numsDivide.size(); j++)
                {
                    if (numsDivide[j]%nums[i]!=0) {isit=1; break;}
                }
                if (isit==0) {return ans;}
                else ans++;
            }
        }
        return -1;
    }
};