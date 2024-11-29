class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        unordered_map<int, int> m;
        m[nums[0]]++;
        ans.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]%2==0)
            {
                int t=nums[i]/2;
                if (m.count(t)>0)
                {
                    m[t]--;
                    if (m[t]==0) m.erase(t);
                }
                else
                {
                    m[nums[i]]++;
                    ans.push_back(nums[i]);
                }
            }
            else
            {
                m[nums[i]]++;
                ans.push_back(nums[i]);
            }
        }
        if (m.size()==0) return ans;
        else return {};
    }
};