class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        stack<int> s;
        s.push(nums.back());
        for (int i=nums.size()-2; i>=0; i--)
        {
            if (nums[i] > s.top())
            {
                int t = 0;
                while (s.size() > 0 && nums[i] > s.top())
                {
                    s.pop();
                    t++;
                }
                if (s.size() > 0) ans[i] = t + 1;
                else ans[i] = t;
                s.push(nums[i]);
            }
            else
            {
                ans[i] = 1;
                s.push(nums[i]);
            }
        }
        return ans;
    }
};