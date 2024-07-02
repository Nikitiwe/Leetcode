class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp, isit(nums.size(), 0);
        int s, sum=nums.size();
        while (sum>0)
        {
            s=0;
            temp.clear();
            while (s!=nums.size())
            {
                if (isit[s]==0&&find(temp.begin(), temp.end(), nums[s])==temp.end())
                {
                    temp.push_back(nums[s]); isit[s]=1; sum--;
                }
                s++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};