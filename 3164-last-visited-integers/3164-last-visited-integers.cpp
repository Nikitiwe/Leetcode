class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> ans, arr;
        int k=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==-1)
            {
                k++;
                if (arr.size()>=k) ans.push_back(arr[arr.size()-k]);
                else ans.push_back(-1);
            }
            else
            {
                k=0;
                arr.push_back(nums[i]);
            }
        }
        return ans;
    }
};