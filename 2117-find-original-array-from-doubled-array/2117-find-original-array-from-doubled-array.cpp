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
                if (m.count(nums[i]/2)>0)
                {
                    m[nums[i]/2]--;
                    if (m[nums[i]/2]==0) m.erase(nums[i]/2);
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